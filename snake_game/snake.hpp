
#include <cstdbool>
#include "key.hpp"
#define BORDER_PAIR     1
#define INC_SNACK_PAIR     2
#define TAIL_PAIR     3
#define BODY_PAIR  4
#define HEAD_PAIR   5
#define GRASS_PAIR 6
struct Snake {
  int x;
  int y;
  int speed;
  char color[3];
  char symbol;
  struct Snake* next;
  enum KEY direction;
};

typedef struct Snake Snake;

Snake* init_snake(int x, int y);
Snake* create_tail(int x, int y);
Snake* move_snake(Snake* snake, int direction);
void draw_snake(Snake* snake);
Snake *get_tail(Snake *snake);
bool eat_itself(Snake* snake, int x, int y);
Snake* remove_tail(Snake* snake);
Snake *grow_tail(Snake *snake, enum KEY);
int len(Snake* snake);

//Check if snake exists at coordinates
bool snake_exists(Snake* foods, int x, int y);