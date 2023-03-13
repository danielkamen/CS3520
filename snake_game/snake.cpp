
#include "key.hpp"
#include "snake.hpp"
#include <cstdbool>
#include <cstdlib>
#include <cstring>
#include <ncurses.h>

// Initialize snake
Snake *init_snake(int x, int y) {
  Snake *head = create_tail(x, y);
  head->direction = RIGHT;
  Snake *tail1 = create_tail(x - 1, y);
  tail1->direction = RIGHT;
  Snake *tail2 = create_tail(x - 2, y);
  tail2->direction = RIGHT;
  tail1->next = tail2;
  head->next = tail1;
  return head;
}

// Creates one tail
Snake *create_tail(int x, int y) {
  Snake *snake = new Snake;
  snake->color[0] = 0;
  snake->color[1] = 0;
  snake->color[2] = 255;
  /* snake->color = {0, 0, 255}; */
  snake->symbol = '#';
  snake->next = NULL;
  snake->x = x;
  snake->y = y;
  return snake;
}

// Moves the snake in the input direction
Snake *move_snake(Snake *snake, int direction) {
  // TODO
  Snake *new_head = new Snake;

  // Set the new head to have the x and y coordinates as the existing head of
  // the snake
  int row = snake->x;
  int col = snake->y;

  switch (direction) {
  case UP:
    col--;
    new_head->direction = UP;
    break;
  case DOWN:
    col++;
    new_head->direction = DOWN;
    break;
  case RIGHT:
    row++;
    new_head->direction = RIGHT;
    break;
  case LEFT:
    row--;
    new_head->direction = LEFT;
    break;
  }

  new_head->x = row;
  new_head->y = col;

  // Set new head as the new head of the entire snake
  new_head->next = snake;
  // Add all the features (color and symbol) to the new cell
  new_head->color[0] = snake->color[0];
  new_head->color[1] = snake->color[1];
  new_head->color[2] = snake->color[2];
  new_head->speed = snake->speed;
  new_head->symbol = snake->symbol;
  //  Delete the tail from the snake: HINT - there is a remove tail function
  //  below
  remove_tail(new_head);

  return new_head;
}

Snake *remove_tail(Snake *snake) {
  Snake *end = snake;
  while (end->next->next)
    end = end->next;
  free(end->next);
  end->next = NULL;
  return snake;
}

Snake *get_tail(Snake *snake) {
  Snake *end = snake;
  while (end->next->next)
    end = end->next;
  return end;
}



bool snake_exists(Snake* foods, int x, int y) {
    Snake* temp = foods;
    while(temp){
        if(temp->x == x && temp->y == y)
            return true;
        temp = temp->next;
    }
    return false;
}

Snake *grow_tail(Snake *snake, KEY key) {
  Snake *temp = snake;
  Snake *oldTail;
  switch (len(snake)) {
  case 1:
    oldTail = temp;
    break;
  case 2:
    oldTail = temp->next;
    break;
  default:
    oldTail = get_tail(temp);
    break;
  }
  int x = oldTail->x;
  int y = oldTail->y;

  switch (oldTail->direction) {
  case LEFT:
    x++;
    break;
  case RIGHT:
    x--;
    break;
  case UP:
    y++;
    break;
  case DOWN:
    y--;
    break;
  }
  Snake *newTail = create_tail(x, y);
  newTail->direction = oldTail->direction;
  newTail->color[0] = oldTail->color[0];
  newTail->color[1] = oldTail->color[1];
  newTail->color[2] = oldTail->color[2];
  newTail->speed = oldTail->speed;
  newTail->symbol = oldTail->symbol;

  if (len(snake) == 1) {
    oldTail->next = newTail;
  } else {
    switch (newTail->direction) {
    case LEFT:
      x++;
      break;
    case RIGHT:
      x--;
      break;
    case UP:
      y++;
      break;
    case DOWN:
      y--;
      break;
    }

    Snake *finalNewTail = create_tail(x, y);
    finalNewTail->direction = newTail->direction;
    finalNewTail->color[0] = oldTail->color[0];
    finalNewTail->color[1] = oldTail->color[1];
    finalNewTail->color[2] = oldTail->color[2];
    finalNewTail->speed = oldTail->speed;
    finalNewTail->symbol = oldTail->symbol;
    oldTail->next = newTail;
    newTail->next = finalNewTail;
  }

  return snake;
}

// draws the snake on the board
void draw_snake(Snake *snake) {
  start_color();
  init_pair(8, COLOR_CYAN, COLOR_BLACK);
  attron(COLOR_PAIR(8));
  int count = 0;
  while (snake->next) {
    mvprintw(snake->y, snake->x, "%c", snake->symbol);
    snake = snake->next;
    count++;
  }
  mvprintw(snake->y, snake->x, "%c", snake->symbol);
  attroff(COLOR_PAIR(8));
}

// checks if it eats itself, if it does, then return true
bool eat_itself(Snake *snake, int x, int y) {
  Snake *temp1 = snake;


  if (len(snake) > 4) {
    temp1 = temp1->next->next->next;
  while (temp1) {
      if (temp1->x == x && temp1->y == y) {
        return true;
        break;
      }
      temp1 = temp1->next;
    }
  }
  return false;
}

int len(Snake *snake) {
  int len = 1;
  while (snake->next) {
    len++;
    snake = snake->next;
  }
  return len;
}