
#include "game.hpp"
#include "key.hpp"
#include "game_window.hpp"
#include <cstdlib>
#include <cstdio>
#include <ncurses.h>

int Input();
int ready();
int x_max, y_max;

int main(void){
    printf("thuoeou");
    if (ready() == '1') {
        game(1);
    } else if (ready() == '2') {
          game(2);
    } else if (ready() == '3') {
          game(3);
    }
    printf("tuenao");
    return(0);
}
 
// sets welcome screen
void setWelcomeScreen()
{

	initscr(); 
	noecho();
	getmaxyx(stdscr, y_max, x_max);
	
}

// gets the users input
int Input()
{
	int input = getch();
	refresh();
	endwin();
	clear();
	return input;	
}

 // print start menu
int ready() 
{
    setWelcomeScreen();
	 move(1, 10);
            printw("Welcome to the snake game!");
            move (2, 10);
            printw("Rules:");
            move(3,10);
            printw("Use the arrow keys to move your snake to collect as many points as possible!");
            move(4, 10);
            printw("You gain points and size by running over the food, which can either make you");
            move(5,10);
            printw("grow or shrink. Vowels makes you grow, while consonants makes you shrink.");
            move(7,10);
            printw("Controls:");
            move(8,10);
            printw("Press [Q] or [q] at anytime to quit the game");
            move(9,10);
            printw("Press [P] or [p] to pause the game");
            move(10,10);
            printw("Avoid the obstacles to stay alive!");
            move(12, 10);
            printw("WARNING: STARTING GAME STARTS IT IMMEDIATLY"); 
            move(14, 30);
            printw("There are three level, [1] is easy, [2] is medium, and [3] is hard"); 
            move(15, 30);
            printw("Press what level you wish to play: "); 
            move(16, 30);
            printw("WARNING: STARTING GAME STARTS IT IMMEDIATLY"); 
	return Input();
}
