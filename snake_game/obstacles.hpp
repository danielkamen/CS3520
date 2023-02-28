#include <ncurses.h>

#define INC_SNACK_PAIR     2
#define TAIL_PAIR     3
#define BODY_PAIR  4
#define HEAD_PAIR   5
#define GRASS_PAIR 6

//Structure to hold properties of Obstacle
struct Obstacle {
  int x;
  int y;
  int width;
  int height;
  char type;
  struct Obstacle* next;
};

typedef struct Obstacle Obstacle;

//Function prototypes 
void add_new_Obstacle(Obstacle* obstacles, Obstacle* new_obstacle);
bool obstacle_exists(Obstacle* obstacles, int x, int y);
Obstacle* create_Obstacle(int x, int y, int endX, int endY);
Obstacle* remove_eaten_Obstacle(Obstacle* obstacles, int x, int y);
void draw_obstacle(Obstacle *obstacle);



