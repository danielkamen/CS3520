
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ncurses.h>
#include <sstream>
#include <string>

#include "bug.hpp"
#include "simulation.hpp"
#include "simulationWindow.hpp"

using namespace std;

void generate_points(int *bugx, int *bugy, int width, int height, int x_offset,
                     int y_offset) {

  *bugx = rand() % width + x_offset + 1;
  *bugy = rand() % height + y_offset + 1;
}

void game(int numDoodle, int numQueen, int numMale, int numWorker) {

  enum State state = INIT;       // Set the initial state
  static int x_max, y_max;       // Max screen size variables
  static int x_offset, y_offset; // distance between the top left corner of your
                                 // screen and the start of the board
  gamewindow_t *window;          // Name of the board

  // instnatiate new objects and containers here
  vector<Bug *> bugs;
  vector<Bug *> tempss;

  const int height = 30;
  const int width = 50;
  char ch;
  int score = 0;
  int Speed = 1;
  int sizeOfX;
  int sizeOfY;

  bool canQueenBreed;

  int numOfAnts = 0;
  int numOfDoodleBugs = 0;

  int printsBugDebug;
  int counterBugs;

  //---------------------------------------------------------
  char charAtSnakeHead;
  int lengthOfSnakeAtTimeOfDeath;
  //------------------------------------------------------------

  srand((int)time(0));
  struct timespec timeret;
  timeret.tv_sec = 200;

  while (state != EXIT) {
    switch (state) {
    case INIT:
      initscr();
      start_color();
      nodelay(stdscr, TRUE); // Dont wait for char
      noecho();              // Don't echo input chars
      getmaxyx(stdscr, y_max, x_max);
      keypad(stdscr, TRUE); // making keys work
      curs_set(0);          // hide cursor
      timeout(100);

      // Setting height and width of the board
      x_offset = (x_max / 2) - (width / 2);
      y_offset = (y_max / 2) - (height / 2);

      // Init board
      window = init_GameWindow(x_offset, y_offset, width, height);

      draw_Gamewindow(window);

      int bugx, bugy, i, j, k, l;
      // Init Bugs
      // adds doodleBugs
      generate_points(&bugx, &bugy, width, height, x_offset, y_offset);
      for (int i = 0; i < numDoodle; i++) {
        while (Bug::bug_exists(bugs, bugx, bugy)) {
          generate_points(&bugx, &bugy, width, height, x_offset, y_offset);
        }
        Bug::addBug(bugs, new DoodleBug(bugx, bugy, 0));
      }

      generate_points(&bugx, &bugy, width, height, x_offset, y_offset);

      // adds the queens
      for (int j = 0; j < numQueen; j++) {
        while (Bug::bug_exists(bugs, bugx, bugy)) {
          generate_points(&bugx, &bugy, width, height, x_offset, y_offset);
        }
        Bug::addBug(bugs, new Queen(bugx, bugy, 0));
      }

      // adds the Workers (non male)
      for (int k = 0; k < numWorker; k++) {
        while (Bug::bug_exists(bugs, bugx, bugy)) {
          generate_points(&bugx, &bugy, width, height, x_offset, y_offset);
        }
        Bug::addBug(bugs, new Worker(bugx, bugy, 0));
      }

      // adds the male Workers
      for (int k = 0; k < numMale; k++) {
        while (Bug::bug_exists(bugs, bugx, bugy)) {
          generate_points(&bugx, &bugy, width, height, x_offset, y_offset);
        }
        Bug::addBug(bugs, new MaleAnt(bugx, bugy, 0));
      }

      state = ALIVE;
      break;

    case ALIVE:
      // if user wants to break program loop
      numOfAnts = 0;
      ch = getch();
      // quit case
      switch (ch) {
      case 81:
      case 113:
        state = EXIT;
        break;
      default:
        break;
      }

      // behavior for moving, breeding, and starving each bug
      for (auto bug : bugs) {

        // queen behavior
        if (auto queen = dynamic_cast<Queen *>(bug)) {
          // can queen starve
          if (queen->starve()) {
            Bug::remove_eaten_bug(bugs, queen->getX(), queen->getY());
            // queen didnt starve, move or breed
          } else {
           
            // checks movement
            vector<pair<int, int>> positions =
                queen->canMove(bugs, queen->x, queen->y);
            if (!(positions.empty())) {
              queen->move(queen, bugs, positions);
            }
          }

        } else if (auto doodlebug = dynamic_cast<DoodleBug *>(bug)) {

          // can doodlebug starve
          if (doodlebug->starve()) {
            Bug::remove_eaten_bug(bugs, doodlebug->getX(), doodlebug->getY());
            // doodlebug didnt starve, move and/or breed
          } else {

            vector<pair<int, int>> positions =
                doodlebug->canMove(bugs, doodlebug->getX(), doodlebug->getY());

            if (!(positions.empty())) {
              doodlebug->move(bug, bugs, positions);
              doodlebug->resetStarveTicks();
            } else {
              doodlebug->incStarve(doodlebug);
            }
          }

        } else if (auto worker = dynamic_cast<Worker *>(bug)) {

          // can worker starve
          if (worker->starve()) {
            Bug::remove_eaten_bug(bugs, worker->getX(), worker->getY());
            // worker didnt starve, move
          } else {
            // checks movement
            vector<pair<int, int>> positions =
                worker->canMove(bugs, worker->getX(), worker->getY());
            if (!(positions.empty())) {
              worker->move(worker, bugs, positions);
              worker->resetStarveTicks();
            } else {
              Bug::incStarve(worker);
            }
          }
        }

        // increment the time for each Bug
        Bug::incTime(bug);
      }

      // Draw everything on the screen
      clear();

      // draws each bug
      for (auto bug : bugs) {

        Bug::draw_Bug(bug);
      }

      draw_Gamewindow(window);
      mvprintw(2, 50, "Key entered: %c", ch);
      mvprintw(3, 50, "Bugs: %i", bugs.size());

      mvprintw(5, 50, "Press [Q] at any time to exit the program");

      // debugging stuff
      printsBugDebug = 10;
      counterBugs = 1;
      for (auto bug : bugs) {
        Bug::display_bug_info(counterBugs, 10, printsBugDebug, bug);
        printsBugDebug++;
        counterBugs++;
      }

      tempss = bugs;
      for (auto bug : tempss) {

        // queen behavior
        if (auto queen = dynamic_cast<Queen *>(bug)) {
          numOfAnts++;
          // checks breeding
          if (queen->canBreed()) {
            queen->breed(bugs);
          } else { 
            queen->incSM();
            queen->incTSQM();
            Bug::incStarve(queen);
          }
        } else if (auto doodlebug = dynamic_cast<DoodleBug *>(bug)) {

          // checks movement
          // checks breeding
          if (doodlebug->canBreed()) {
            doodlebug->breed(bugs);
          }
        } else if (auto worker = dynamic_cast<Worker *>(bug)) {
          numOfAnts++;
        }
      }
      mvprintw(4, 50, "Ants: %i", numOfAnts);
      break;

    case DEAD:
      clear();
      refresh();
      undraw_Gamewindow(window);

      state = EXIT;
      break;
    }
    refresh();
    nanosleep(&timeret, NULL);
  }
}