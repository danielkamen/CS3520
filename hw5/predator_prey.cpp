#include "simulation.hpp"
#include "simulationWindow.hpp"

#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ncurses.h>
#include <vector>

using namespace std;

vector<int> Input();
int ready();
int inputValidation(int minSize);
int x_max, y_max;

int main(void){
    printf("thuoeou");
      vector<int> nums = ready();
   if (nums.size() == 4) {
    game(nums.get(0), nums.get(1), nums.get(2), nums.get(3));
   }
    printf("tuenao");
    return(0);
}
 


  // print start menu
int ready() 
{
    setWelcomeScreen();
	 move(1, 10);
            printw("Welcome to the simulation!");
           
	return Input();
}



// sets welcome screen
void setWelcomeScreen()
{
	initscr(); 
	noecho();
	getmaxyx(stdscr, y_max, x_max);
	
}


// gets the users input
vector<int> Input()
{
    vector<int> nums;
	nums.push_back(inputValidation(1, "Enter number of doodlebugs: "));
   nums.push_back(inputValidation(1,  "Enter number of queens: "));
    nums.push_back(inputValidation(1,  "Enter number of male ants: "));
   nums.push_back(inputValidation(0,  "Enter number of worker ants: "));
	refresh();
	endwin();
	clear();
	return nums;	
}


// input validation
int inputValidation(int minSize, string message) {
    cout<<message<<endl;
    int value;
    // input validation
    while (!(cin>>value) || value < minSize) {
      cout<<"Try again, not a number or less than" + " " + minSize "."<<endl;
      cin.clear();
      cin.ignore(123,'\n');
    }

    return value;
}

