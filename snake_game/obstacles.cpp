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

void add_new_Obstacle_SubList(Obstacle* obstacles, Obstacle* new_obstacle) {
        Obstacle* temp = obstacles->nextSubList;
     while(temp->nextSubList) {
        temp = temp->nextSubList;
    }
    temp->nextSubList = new_obstacle;
}



// iterates over the obstacle and subObstacle lists
bool obstacle_exists(Obstacle* obstacles, int x, int y) {
     Obstacle* temp = obstacles;
     bool found = false;
    while(temp){
        Obstacle* subListTemp = temp->nextSubList;
        while(subListTemp) {
            if(subListTemp->x == x && subListTemp->y == y) {
                found = true;
            }
            subListTemp = subListTemp->next;
        }
        temp = temp->next;
    }
    return found;
}


// ALWAYS ASSUME ENDX AND ENDY WILL BE AVLID POINTS LARGER THAN X and Y!!!!!

Obstacle* create_Obstacle(int x, int y, int endX, int endY) {
    Obstacle* new_Obstacle = (Obstacle*)malloc(sizeof(Obstacle));
    Obstacle* sublist, *new_sublistItem;
    sublist = create_sub_Obstacle(x, y);
    new_Obstacle->x = x;
    new_Obstacle->y = y;
    new_Obstacle->type = '^';
    new_Obstacle->next = NULL;
    new_Obstacle->nextSubList = sublist;
    
    new_sublistItem = sublist->nextSubList;
    for (int w = y; w < endY + y; w++) {
        for (int q = x; q <endX  + x; q++) {
            new_sublistItem = create_sub_Obstacle(q + 1, w); 
            new_sublistItem = new_sublistItem->nextSubList;
        }
    }
    return new_Obstacle;
}

Obstacle* create_sub_Obstacle(int x, int y) {
    Obstacle* new_Obstacle = (Obstacle*)malloc(sizeof(Obstacle));
    new_Obstacle->x = x;
    new_Obstacle->y = y;
    new_Obstacle->type = '@';
    new_Obstacle->next = NULL;
    new_Obstacle->nextSubList = NULL;
    return new_Obstacle;
}

// Issue to keep in mind: this coordinate can point ANY subObstacle within the list of obstacles. So I must apply logic from remove eaten food to seach sublists of each item, and if the square exists, update master list of obstacles,

// should i free up memeory of sublist if i remove memeory of main list item?

// will need helper method to iterate through sublist,
Obstacle* remove_eaten_Obstacle(Obstacle* obstacles, int x, int y) {
    Obstacle* newObstacle = obstacles;     

    // first item edge case
    // the obstacle exists within the sublist, remove the referance to Master Obstacle
     if (obstacle_exists(newObstacle, x, y)) {
            free(newObstacle);
            newObstacle = newObstacle->next;
            return newObstacle;
        }

    // all items between 2 and n-1 
    while (newObstacle->next->next) {
             // checks the second -> n-1 foods
        if (obstacle_exists(newObstacle->next, x, y)) {
            newObstacle->next = newObstacle->next->next;
            break;
        } 
         newObstacle = newObstacle->next;
    }
   
    // nth item check
     if (obstacle_exists(newObstacle->next, x, y)) {
         free(newObstacle->next);
          newObstacle->next = NULL;
         }

    return obstacles;
}



void draw_obstacle(Obstacle *obstacle)
{   Obstacle* temp = obstacle;
    while(temp) {

        Obstacle* subListTemp = temp->nextSubList;
        while(subListTemp) {
         mvprintw(subListTemp->y, subListTemp->x, "%c", subListTemp->type);
            subListTemp = subListTemp->nextSubList;
        }
        temp = temp->next;
    } 
    
}