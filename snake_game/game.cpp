#include "food.hpp"
#include "game.hpp"
#include "game_window.hpp"
#include "key.hpp"
#include "obstacles.hpp"
#include "snake.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <bits/stdc++.h>

using  namespace std;

void generate_points(int *food_x, int *food_y, int width, int height,
                     int x_offset, int y_offset) {

  *food_x = rand() % width + x_offset + 1;
  *food_y = rand() % height + y_offset + 1;
}

void generate_Obstacl_Point(int *obs_x, int *obs_y, int width, int height,
                            int x_offset, int y_offset, int sizeOfObstacleX,
                            int sizeOfObstacleY, int level) {
                              int safeRange = 5- level;
  // x and y offset equal the top left corner starting position
  // height and width refer to size of board
  // want positions from 1+ top/ left edges up until height/wdith - obsy/x
  // respectivly

  *obs_x = rand() % (width - sizeOfObstacleX - 2) + x_offset + 1;
  *obs_y = rand() % (height - sizeOfObstacleY - 2) + y_offset + 1;
      while (((*obs_x > x_offset + (width/2) - safeRange) || ((*obs_x + sizeOfObstacleX > x_offset + (width/2) - safeRange)))
      &&
      ((*obs_x > x_offset + (width/2) + safeRange) || ((*obs_x + sizeOfObstacleX > x_offset + (width/2) + safeRange)))
       &&
       ((*obs_y > y_offset + (height/2) - safeRange / 2) || ((*obs_y + sizeOfObstacleY > y_offset + (height/2) - safeRange / 2)))
       &&
       ((*obs_y > y_offset + (height/2) + safeRange / 2) || ((*obs_y + sizeOfObstacleY > y_offset + (height/2) + safeRange / 2)))) {
        *obs_x = rand() % (width - sizeOfObstacleX - 2) + x_offset + 1;
        *obs_y = rand() % (height - sizeOfObstacleY - 2) + y_offset + 1;
      }
}

void game(int level) {
  enum State state = INIT;       // Set the initial state
  enum KEY key = LEFT;           // set inital direction to left
  static int x_max, y_max;       // Max screen size variables
  static int x_offset, y_offset; // distance between the top left corner of your
                                 // screen and the start of the board
  gamewindow_t *window;          // Name of the board
  Snake *snake, *listTempSnake, *tailSnakeEndGame; // The snake
  Food *foods, *new_food, *listTempFoods; // List of foods (Not an array)
  Obstacle *obstacles, *new_Obstacle, *temp, *listTempObs;

  const int height = 30;
  const int width = 70;
  char ch;
  int score = 0;
  int Speed = 1;
  int sizeOfX;
  int sizeOfY;
  int numOfObstacles;
  int numOfFood;
  int printsObstacleCoordsDebug;
  int printsFoodCoordsDebug;
  int printsSnakeCoordsDebug;
  int counterFood;
  int counterObs;
  int lives = 3;
  char charAtSnakeHead;
  int lengthOfSnakeAtTimeOfDeath;

  srand((int)time(0));
  struct timespec timeret;
  timeret.tv_sec = 0;
  timeret.tv_nsec = 999999999 / (4 * Speed);

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

      // Init snake
      snake = init_snake(x_offset + (width / 2), y_offset + (height / 2));
      snake->speed = 1 * level * level;

      // Init foods
      int food_x, food_y, i;
      enum Type type;

      // init obstacles
      int obs_x, obs_y, k;
      sizeOfX = (rand() % 7) + 1;
      sizeOfY = (rand() % 7) + 1;

      // generate 3-10 obstacles of random size
      generate_Obstacl_Point(&obs_x, &obs_y, width, height, x_offset, y_offset,
                             sizeOfX, sizeOfY, level);
      obstacles = create_Obstacle(obs_x, obs_y, sizeOfX, sizeOfY);

      // init random number of obstacles
      numOfObstacles = (rand() % 7) + 3 + level * 2;
      for (k = 0; k < numOfObstacles; k++) {
        sizeOfX = (rand() % 10) + 1;
        sizeOfY = (rand() % 10) + 1;
        generate_Obstacl_Point(&obs_x, &obs_y, width, height, x_offset,
                               y_offset, sizeOfX, sizeOfY, level);
        while (obstacle_exists(obstacles, obs_x, obs_y)) {
          generate_Obstacl_Point(&obs_x, &obs_y, width, height, x_offset,
                                 y_offset, sizeOfX, sizeOfY, level);
        }
        new_Obstacle = create_Obstacle(obs_x, obs_y, sizeOfX, sizeOfY);
        add_new_Obstacle(obstacles, new_Obstacle);
      }

      // Generate 10 foods
      generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
      type = (rand() > RAND_MAX / 2)
                 ? Increase
                 : Decrease; // Randomly deciding type of food

      foods = create_food(food_x, food_y, type, rand() % 3);
      // init random number of food
      numOfFood = (rand() % 7) + 3 + level * 2;
      for (i = 1; i < numOfFood; i++) {
        generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
        while (food_exists(foods, food_x, food_y) ||
               obstacle_exists(obstacles, food_x, food_y))
          generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
        type = (rand() > RAND_MAX / 2) ? Increase : Decrease;
        new_food = create_food(food_x, food_y, type, rand() % 3);
        add_new_food(foods, new_food);
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
      case 80:
      case 112:
        timeout(-1);
        ch = get_char();
        while (ch != 80 && ch != 112) {
          if (ch == 81 || ch == 113) {
            state = EXIT;
            timeout(100);
            break;
          };
        }
        timeout(100);
        break;
      case LEFT:
        if (key != LEFT && key != RIGHT) {
          key = LEFT;
        }
        break;
      case RIGHT:
        if (key != RIGHT && key != LEFT) {
          key = RIGHT;
        }
        break;
      case UP:
        if (key != UP && key != DOWN) {
          key = UP;
        }
        break;
      case DOWN:
        if (key != DOWN && key != UP) {
          key = DOWN;
        }
        break;
      default:
        break;
      }
      snake->speed = snake->speed + (score / 100);
      if (snake->speed == 1) {
        Speed = 1;
      } else {
        Speed = 10000005 * snake->speed * level * level;
      }
      // moves snake based on that key value
      snake = move_snake(snake, key);

      enum Type newType;
      enum Type oldFoodType;
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
        if (obstacle_exists(obstacles, snake->x, snake->y)) {
          obstacles = remove_eaten_Obstacle(obstacles, snake->x, snake->y);
          lives--;
          snake = instantiateDeadSnake(snake, lengthOfSnakeAtTimeOfDeath, width,
                                       height, x_offset, y_offset);
          key = RIGHT;
        }
        charAtSnakeHead = mvinch(snake->y, snake->x) &  A_CHARTEXT;
        if ((charAtSnakeHead == '*')) {
          lives--;
          snake = instantiateDeadSnake(snake, lengthOfSnakeAtTimeOfDeath, width,
                                       height, x_offset, y_offset);
          key = RIGHT;
        }
        if (eat_itself(snake, snake->x, snake->y)) {
          lives--;
          snake = instantiateDeadSnake(snake, lengthOfSnakeAtTimeOfDeath, width,
                                       height, x_offset, y_offset);
          key = RIGHT;
        }

      } else {
        state = DEAD;
      }
      // Draw everything on the screen
      clear();

      draw_snake(snake);
      draw_obstacle(obstacles);
      draw_food(foods);
      draw_Gamewindow(window);
      mvprintw(2, 50, "Key entered: %c", ch);
      mvprintw(3, 50, "Score: %i", score);
      mvprintw(4, 50, "Lives: %i", lives);
      mvprintw(5, 50, "Length: %i", len(snake));
      mvprintw(6, 50, "Level: %i", level);

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
      counterFood = 1;
      while (listTempFoods) {

        mvprintw(printsFoodCoordsDebug + 7, 5,
                 "[%i] Food: x %i, y %i, t %i, sT %c ", counterFood,
                 listTempFoods->x, listTempFoods->y, listTempFoods->type,
                 listTempFoods->subType);
        counterFood++;
        printsFoodCoordsDebug++;
        listTempFoods = listTempFoods->next;
      }

      counterFood = 1;
      while (listTempSnake) {

        mvprintw(printsFoodCoordsDebug + 10, 5, "[%i] Snake: x %i, y %i",
                 counterFood, listTempSnake->x, listTempSnake->y);
        counterFood++;
        printsFoodCoordsDebug++;
        listTempSnake = listTempSnake->next;
      }

      break;

    case DEAD:
      clear();
      refresh();
      undraw_Gamewindow(window);
      setEndScreen(score, len(snake));
      endwin();
      state = EXIT;
      break;
    }
    refresh();
    nanosleep(&timeret, NULL);
  }
}

Snake *instantiateDeadSnake(Snake *snake, int OldSize, int width, int height,
                            int x_offset, int y_offset) {
  Snake *temp = init_snake(x_offset + (width / 2), y_offset + (height / 2));

  while (OldSize != len(temp)) {
    if (OldSize > len(temp)) {
      temp = grow_tail(temp, RIGHT);
    }
    if (OldSize < len(temp)) {
      temp = remove_tail(temp);
    }
  }
  snake = temp;

  return snake;
}

// sets end screen
void setEndScreen(int score, int length) {
  int x_max, y_max;
  initscr();
  noecho();
  getmaxyx(stdscr, y_max, x_max);
  move(1, 10);
  printw("Game Over!");
  move(2, 10);
  printw("Final Length: %i", length);
  move(3, 10);
  printw("Points: %i", score);
  move(4, 10);
  // -1 if not in top 10
  int place = get_and_sort_leaderboard(score);
  if (place > 0) {
    printw("All time rank: %i", place);
  } else {
    printw("All time rank: Not in top 10", place);
  }
 move(8, 10);
 attrset(A_NORMAL);
  refresh();
  endwin();
}



int get_and_sort_leaderboard(int newScore) {
  const string filename = "./save/save_best_10.game";
    vector<int> scores;
    int score;
    ifstream infile(filename);
    int indexOfPos = -1;

    while (infile >> score) {
        scores.push_back(score);
    }


    scores.push_back(newScore);
    sort(scores.begin(), scores.end(), greater<int>());
    if (scores.size() > 10) {
    scores.pop_back();
    }
    ofstream outfile(filename);
    for (int i = 0; i < scores.size(); i++) {
        outfile << scores[i] << endl;
    }
    for (int w = 0; w < scores.size(); ++w)
{
    if (newScore == scores[w]) {
      indexOfPos = w + 1;
    }
}

    return indexOfPos;
}