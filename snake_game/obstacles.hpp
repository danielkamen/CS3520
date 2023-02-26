#include <ncurses.h>



//Structure to hold properties of food
struct Obstacle {
  int x;
  int y;
  char type;
  struct Obstacle* next;
  struct Obstacle* nextSubList;
};

typedef struct Food Food; 

//Function prototypes 
void add_new_Obstacle(Obstacle* obstacles, Obstacle* new_obstacle);
void add_new_Obstacle_SubList(Obstacle* obstacles, Obstacle* new_obstacle);
bool obstacle_exists(Obstacle* obstacles, int x, int y);
Obstacle* create_Obstacle(int x, int y, int endX, int endY);
Obstacle* create_sub_Obstacle(int x, int y);
Obstacle* remove_eaten_Obstacle(Obstacle* obstacles, int x, int y);
void draw_obstacle(Obstacle *obstacle);


