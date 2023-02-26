

#include <cstdlib>
#include <stdlib.h> 
#include <ncurses.h>
#include <cstdbool>
#include <time.h>
#include "food.hpp"

//Create new food
Food* create_food(int x, int y, enum Type type, int randNum){
    Food* new_food = (Food*)malloc(sizeof(Food));
    int ran = randNum;
    new_food->x = x;
    new_food->y = y;
    if (type == Increase){
        new_food->type = 'O';
        switch(ran) {
            case (0):
            new_food->subType = 'E';
            break;
            case (1):
            new_food->subType = 'U';
            break;
            default:
            new_food->subType = 'A';
            break;
        }
    }
    else if (type == Decrease){
        new_food->type = 'X';
        switch(ran) {
            case (0):
                 new_food->subType = 'X';
                 break;
            case (1):
                 new_food->subType = 'H';
                 break;
            default:
                  new_food->subType = 'L';
                  break;
        }
    }
    new_food->next = NULL;

    return new_food;
}

//Check if food exists at coordinates
bool food_exists(Food* foods, int x, int y){
    Food* temp = foods;
    while(temp){
        if(temp->x == x && temp->y == y)
            return true;
        temp = temp->next;
    }
    return false;
}

//Add new food to end of food list
void add_new_food(Food* foods, Food* new_food){
    Food* temp = foods;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = new_food;
}

// assumes this is called at a spot that contains a food. So call if food_exists -> food_type
enum Type food_type(Food* foods, int x, int y) {
    Food* temp = foods;
        while(temp){
        if(temp->x == x && temp->y == y)
            if (temp->type=='O') {
                return Increase;
                break;
            } else if (temp->type=='X'){
                return Decrease;
                break;
            }
        temp = temp->next;
    }	
}

// assumes this is called at a spot that contains a food. So call if food_exists -> remove_eaten_food. Can remove multiple peices at the same spot, two snacks initalized at same spot
Food* remove_eaten_food(Food* foods, int x, int y){
    Food* newFood = foods;     
    // first item edge case
     if (newFood->x == x && newFood->y == y) {
            free(newFood);
            newFood = newFood->next;
            return newFood;
        }

    // all items between 2 and n-1 
    while (newFood->next->next) {
             // checks the second -> n-1 foods
        if (newFood->next->x == x && newFood->next->y == y) {
            newFood->next = newFood->next->next;
            break;
        } 
         newFood = newFood->next;
    }
   
    // nth item check
     if (newFood->next->x == x && newFood->next->y == y) {
         free(newFood->next);
          newFood->next = NULL;
         }

    return foods;
}

// Display all the food
void draw_food (Food *foods)
{   Food* temp = foods;
    while(temp) {
        mvprintw(temp->y, temp->x, "%c", temp->subType);
        temp = temp->next;
    } 
    
}
