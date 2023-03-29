#include "bug.hpp"
#include "simulation.hpp"
#include "simulationWindow.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ncurses.h>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int value;
  vector<int> nums;

  cout << "Enter number of doodlebugs, queens, male ants, and workers (in that "
          "order) by entering a number, then enter, then again: "
       << endl;

  for (int i = 0; i < 4; i++) {
    while (!(cin >> value) || value < 0) {
      cout << "Try again, not a number or less than 0" << endl;
      cin.clear();
      cin.ignore(123, '\n');
    }

    nums.push_back(value);
  }
  while (nums.at(0) + nums.at(1) + nums.at(2) +nums.at(3) > 1500) {
    cout<<"You gave too many bugs. try again"<<endl;
    nums.clear();
      for (int i = 0; i < 4; i++) {
    while (!(cin >> value) || value < 0) {
      cout << "Try again, not a number or less than 0" << endl;
      cin.clear();
      cin.ignore(123, '\n');
    }

    nums.push_back(value);
  }
  }

  game(nums.at(0), nums.at(1), nums.at(2), nums.at(3));

  return (0);
}
