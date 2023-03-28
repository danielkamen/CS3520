
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>



#include "bug.hpp"
#include "simulationWindow.hpp"
#include "simulation.hpp"


using  namespace std;

void generate_points(int *bugx, int *bugy, int width, int height,
                     int x_offset, int y_offset) {

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
vector<Bug> bugs;



  const int height = 100;
  const int width = 100;
  char ch;
  int score = 0;
  int Speed = 1;
  int sizeOfX;
  int sizeOfY;

  int printsObstacleCoordsDebug;


  char charAtSnakeHead;
  int lengthOfSnakeAtTimeOfDeath;

  srand((int)time(0));
  struct timespec timeret;
  timeret.tv_sec = 1;

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
        while (bug_exists(bugs, bugx, bugy)) {
            generate_points(&bugx, &bugy, width, height, x_offset, y_offset);
        }
     addBug(bugs,new DoodleBug(bugx, bugy, 0));
     }

        generate_points(&bugx, &bugy, width, height, x_offset, y_offset);

        // adds the queens
     for (int j = 0; j < numQueen; j++) {
        while (bug_exists(bugs, bugx, bugy)) {
            generate_points(&bugx, &bugy, width, height, x_offset, y_offset);
        }
     addBug(bugs,new Queen(bugx, bugy, 0));
     }

          // adds the Workers (non male)
     for (int k = 0; k < numWorker; k++) {
        while (bug_exists(bugs, bugx, bugy)) {
            generate_points(&bugx, &bugy, width, height, x_offset, y_offset);
        }
    addBug(bugs,new Worker(bugx, bugy, 0));
     }

     // adds the male Workers 
     for (int k = 0; k < numWorker; k++) {
        while (bug_exists(bugs, bugx, bugy)) {
            generate_points(&bugx, &bugy, width, height, x_offset, y_offset);
        }
        addBug(bugs,new MaleAnt(bugx, bugy, 0));
    
     }

      state = ALIVE;
      break;

    case ALIVE:
      ch = get_char();
      // determiens what the key is
      switch (ch) {
      case 81:
      case 113:
        state = EXIT;
        break;
      default:
        break;
      }
   
      // moves snake based on that key value
      snake = move_snake(snake, key);


    // -----------------
    // for each doodlebug, check if there are any ants in its radius, make a temp list of those, make a random number, and go to that postion in list ant to eat. 
      if (food_exists(foods, snake->x, snake->y)) {
        oldFoodType = food_type(foods, snake->x, snake->y);
        if (oldFoodType == Increase) {
          snake = grow_tail(snake, key);
          score += 20;
        } else {
          if (len(snake) > 1) {
            snake = remove_tail(snake);
            score -= 10;
          } else {
            score -= 10;
            // CASE FOR WHEN SNAKE HAS GOTTEN TO 0 SIZE (ENDGAME)
            lives--;
            snake = instantiateDeadSnake(snake, lengthOfSnakeAtTimeOfDeath,
                                         width, height, x_offset, y_offset);
            key = RIGHT;
          }
        }
        foods = remove_eaten_food(foods, snake->x, snake->y);
        generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
        while (food_exists(foods, food_x, food_y) ||
               obstacle_exists(obstacles, food_x, food_y)) {
          generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
        }
        newType = (rand() > RAND_MAX / 2) ? Increase : Decrease;
        new_food = create_food(food_x, food_y, newType, rand() % 3);
        add_new_food(foods, new_food);
      }
      lengthOfSnakeAtTimeOfDeath = len(snake);




      if (lives > 0) {
        // number of ants is not 0
      } else {
        state = DEAD;
      }


      // Draw everything on the screen
      clear();


      // -----------------
      draw_snake(snake);
      // -----------------


      draw_Gamewindow(window);
      mvprintw(2, 50, "Key entered: %c", ch);
    
    // -----------------
    // print the current time
      mvprintw(6, 50, "Level: %i", level);
// -----------------

// -----------------
// update this to reflect new data reps, ie list of bugs

      printsObstacleCoordsDebug = 10;
      printsFoodCoordsDebug = printsObstacleCoordsDebug + numOfObstacles;
      listTempSnake = snake;
      listTempObs = obstacles;
      listTempFoods = foods;
      counterObs = 1;
      while (listTempObs) {

        mvprintw(printsObstacleCoordsDebug, 5,
                 "[%i] Obs: x %i, y %i, w %i, h %i ", counterObs,
                 listTempObs->x, listTempObs->y, listTempObs->width,
                 listTempObs->height);

        counterObs++;
        printsObstacleCoordsDebug++;
        listTempObs = listTempObs->next;
      }


      break;

    case DEAD:
      clear();
      refresh();
      undraw_Gamewindow(window);
      endwin();
      state = EXIT;
      break;
    }
    refresh();
    nanosleep(&timeret, NULL);
  }
}