#include "obstacles.hpp"

#include <cstdlib>
#include <ncurses.h>
#include <cstdbool>


// mutates the HIGHER LEVEL obstacle list, where each item points to a sublist whcih is what is drawn/ represented ons creen.
void add_new_Obstacle(Obstacle* obstacles, Obstacle* new_obstacle) {
        Obstacle* temp = obstacles;
     while(temp->next) {
         temp = temp->next;
        }
          temp->next = new_obstacle;
}




// iterates over the obstacle and checks its bounds
bool obstacle_exists(Obstacle* obstacles, int x, int y) {
     Obstacle* temp = obstacles;
     bool found = false;
    while(temp){
            if (((x >= temp->x) && x < (temp->x + temp->width)) && ((y >= temp->y) && y < (temp->y + temp->height))) {
                    return true;
                }
        temp = temp->next;
    }
    return found;
}


// ALWAYS ASSUME ENDX AND ENDY WILL BE AVLID POINTS LARGER THAN X and Y!!!!!
// endX and endY represent the actual grid value where the obstacle will end. Start top left, end bottom right.
Obstacle* create_Obstacle(int x, int y, int endX, int endY) {
    Obstacle* new_Obstacle = (Obstacle*)malloc(sizeof(Obstacle));
    Obstacle* sublist;
    new_Obstacle->x = x;
    new_Obstacle->y = y;
    new_Obstacle->width = endX;
    new_Obstacle->height = endY;
    // different for sanity checks
    new_Obstacle->type = '*';
    new_Obstacle->next = NULL;
    
    return new_Obstacle;
}


// Issue to keep in mind: this coordinate can point ANY subObstacle within the list of obstacles. So I must apply logic from remove eaten food to seach sublists of each item, and if the square exists, update master list of obstacles,

// should i free up memeory of sublist if i remove memeory of main list item?

// will need helper method to iterate through sublist,
Obstacle* remove_eaten_Obstacle(Obstacle* obstacles, int x, int y) {
    Obstacle* newObstacle = obstacles;     

    // first item edge case
    // the obstacle exists within the sublist, remove the referance to Master Obstacle
     if (((x >= newObstacle->x) && x < (newObstacle->x + newObstacle->width)) && ((y >= newObstacle->y) && y < (newObstacle->y + newObstacle->height))) {
            free(newObstacle);
            newObstacle = newObstacle->next;
            return newObstacle;
        }

    // all items between 2 and n-1 
    while (newObstacle->next->next) {
             // checks the second -> n-1 foods
        if (((x >= newObstacle->next->x) && x < (newObstacle->next->x + newObstacle->next->width)) && ((y >= newObstacle->next->y) && y < (newObstacle->next->y + newObstacle->next->height))) {
            newObstacle->next = newObstacle->next->next;
            break;
        } 
         newObstacle = newObstacle->next;
    }

    // nth item check
     if (((x >= newObstacle->next->x) && x < (newObstacle->next->x + newObstacle->next->width)) && ((y >= newObstacle->next->y) && y < (newObstacle->next->y + newObstacle->next->height))) {
         free(newObstacle->next);
          newObstacle->next = NULL;
         }

    return obstacles;
}



void draw_obstacle(Obstacle *obstacle)
{   Obstacle* temp = obstacle;
start_color();
init_pair(TAIL_PAIR, COLOR_RED, COLOR_WHITE);
  attron(COLOR_PAIR(TAIL_PAIR));
    while(temp) {
        
        for (int h = temp->y; h < temp->y + temp->height; h++) {
                 for (int w = temp->x; w < temp->x + temp->width; w++) {
                 mvprintw(h, w, "%c", temp->type);
                }
            }
        temp = temp->next;
    } 
      attroff(COLOR_PAIR(TAIL_PAIR));
    
}