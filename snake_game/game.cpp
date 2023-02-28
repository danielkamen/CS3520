#include "food.hpp"
#include "game.hpp"
#include "game_window.hpp"
#include "key.hpp"
#include "snake.hpp"
#include "obstacles.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

 
void generate_points(int *food_x, int *food_y, int width, int height,
                     int x_offset, int y_offset) {
  *food_x = rand() % width + x_offset + 1;
  *food_y = rand() % height + y_offset + 1;
}

void generate_Obstacl_Point(int *obs_x, int *obs_y, int width, int height,
                     int x_offset, int y_offset, int sizeOfObstacleX, int sizeOfObstacleY) {
                      // x and y offset equal the top left corner starting position
                      // height and width refer to size of board
                      // want positions from 1+ top/ left edges up until height/wdith - obsy/x respectivly
  *obs_x = rand() % (width - sizeOfObstacleX - 2) + x_offset + 1;
  *obs_y = rand() % (height - sizeOfObstacleY - 2) + y_offset + 1;
}


void game() {
  enum State state = INIT;       // Set the initial state
  enum KEY key = LEFT;           // set inital direction to left
  static int x_max, y_max;       // Max screen size variables
  static int x_offset, y_offset; // distance between the top left corner of your
                                 // screen and the start of the board
  gamewindow_t *window;          // Name of the board
  Snake *snake, *listTempSnake, *tailSnakeEndGame;                  // The snake
  Food *foods, *new_food, *listTempFoods;        // List of foods (Not an array)
  Obstacle* obstacles, *new_Obstacle, *temp, *listTempObs;

  const int height = 30;
  const int width = 70;
  char ch;
  int score = 0;
  int Speed = 1;
  int sizeOfX;
  int sizeOfY;
  int numOfObstacles;
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
      snake->speed = 1;

      // Init foods
      int food_x, food_y, i;
      enum Type type;


      // init obstacles
      int obs_x, obs_y, k;
      sizeOfX = (rand() % 6) + 1;
      sizeOfY = (rand() % 6) + 1;

      // generate 3-10 obstacles of random size
      generate_Obstacl_Point(&obs_x, &obs_y, width, height, x_offset, y_offset, sizeOfX, sizeOfY);
      obstacles = create_Obstacle(obs_x, obs_y, sizeOfX, sizeOfY);

      // init random number of obstacles
      numOfObstacles = (rand() % 7) + 3;
      for (k = 0; k <8; k++) {
        sizeOfX = (rand() % 6) + 1;
        sizeOfY = (rand() % 6) + 1;
        generate_Obstacl_Point(&obs_x, &obs_y, width, height, x_offset, y_offset, sizeOfX, sizeOfY);
      while(obstacle_exists(obstacles, obs_x, obs_y)) {
        generate_Obstacl_Point(&obs_x, &obs_y, width, height, x_offset, y_offset, sizeOfX, sizeOfY);
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
      for (i = 1; i < 10; i++) {
        generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
        while (food_exists(foods, food_x, food_y))
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
        while(ch !=80 && ch !=112) {
          if (ch  == 81 ||ch ==113) {
            state = EXIT;
            timeout(100);
            break;
          }
            ;
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
        Speed = 10000005 * snake->speed;
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
        } else if (len(snake) > 1) {
            snake = remove_tail(snake);
            score -= 10;
          } else if (len(snake) == 1) {
            lives--;
          
          }
        foods = remove_eaten_food(foods, snake->x, snake->y);
        generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
        while (food_exists(foods, food_x, food_y)) {
          generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
        }
        newType = (rand() > RAND_MAX / 2) ? Increase : Decrease;
        new_food = create_food(food_x, food_y, newType, rand() % 3);
        add_new_food(foods, new_food);
      }

      
      if (lives > 0) {
      if (obstacle_exists(obstacles, snake->x, snake->y)) {
        obstacles = remove_eaten_Obstacle(obstacles, snake->x, snake->y);
        lengthOfSnakeAtTimeOfDeath = len(snake);
        lives--;
        snake = instantiateDeadSnake(snake, lengthOfSnakeAtTimeOfDeath, width, height, x_offset, y_offset);
      }
      if (eat_itself(snake)) {
        lives--;
        snake = init_snake(x_offset + (width / 2), y_offset + (height / 2));
        snake = instantiateDeadSnake(snake, lengthOfSnakeAtTimeOfDeath, width, height, x_offset, y_offset);
      }
      charAtSnakeHead = chtype(mvinch(snake->x, snake->y));
      if (charAtSnakeHead == '*') {
        lives--;
        snake = init_snake(x_offset + (width / 2), y_offset + (height / 2));
        snake = instantiateDeadSnake(snake, lengthOfSnakeAtTimeOfDeath, width, height, x_offset, y_offset);
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
      printsObstacleCoordsDebug = 10;
      printsFoodCoordsDebug = printsObstacleCoordsDebug + numOfObstacles;
      listTempSnake = snake;
      listTempObs = obstacles;
      listTempFoods = foods;
      counterObs = 1;
      while (listTempObs) {

        mvprintw(printsObstacleCoordsDebug, 5, "[%i] Obs: x %i, y %i, w %i, h %i ", counterObs, listTempObs->x, listTempObs->y, listTempObs->width, listTempObs->height);
        
        counterObs++;
        printsObstacleCoordsDebug++;
        listTempObs = listTempObs->next;
      }
      counterFood = 1;
      while (listTempFoods) {
 
        mvprintw(printsFoodCoordsDebug + 7, 5, "[%i] Food: x %i, y %i, t %i, sT %c ",counterFood, listTempFoods->x, listTempFoods->y, listTempFoods->type, listTempFoods->subType);
        counterFood++;
        printsFoodCoordsDebug++;
        listTempFoods = listTempFoods->next;
      }

       counterFood = 1;
      while (listTempSnake) {
 
        mvprintw(printsFoodCoordsDebug + 10, 5, "[%i] Snake: x %i, y %i",counterFood, listTempSnake->x, listTempSnake->y);
        counterFood++;
        printsFoodCoordsDebug++;
        listTempSnake = listTempSnake->next;
      }

      break;

    case DEAD:

     setEndScreen(score, len(snake));
      endwin();
      break;
    
    }
    refresh();
    nanosleep(&timeret, NULL);
  }
}

Snake* instantiateDeadSnake(Snake* snake, int OldSize, int width, int height, int x_offset, int y_offset) {
  Snake* temp = snake;
        snake = init_snake(x_offset + (width / 2), y_offset + (height / 2));
          while (OldSize > len(temp)) {
            temp = get_tail(snake);

Snake *newTail = create_tail(temp->x + 1,temp->y);
            temp->next = newTail;
            temp = temp->next;
          }
          while (OldSize < len(temp)) {
            temp = remove_tail(temp);
          }
          return snake;
}

// sets end screen
void setEndScreen(int score, int length)
{
 int x_max, y_max;
	initscr(); 
	noecho();
	getmaxyx(stdscr, y_max, x_max);
  move(1, 10);
            printw("Game Over!");
            move (2, 10);
            printw("Final Length: %i", length);
            move(3,10);
            printw("Points: %i", score);
            move(4, 10);
            // 11 if not in top 10
            printw("All time rank:");
            move(7,10);
            printw("WARNING: STARTING GAME STARTS IT IMMEDIATLY"); 
            refresh();
            endwin();
	
}




