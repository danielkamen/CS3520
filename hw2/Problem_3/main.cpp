#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class MazeGenerator {
public:
    string border;
    string path;
    vector<vector<string> > mazeMade;
    // generates a pointer to the array 
    void mazeGenerator(int sizes) {
        // min path is 3, and 100 is used to just not make a super big maze for this assignment
        int min = 3;
        int max = 40;
        if (sizes < min || sizes > max) {
            cout << "Hey, you can't make a " << sizes << "x" << sizes << " maze. Call this method again with a size between " << min << " and " << max << "." << endl;
        }
<<<<<<< HEAD

        else {
            vector<vector<string> > board;
            for (int i = 0; i < sizes; i++) {
                vector<string> row;
=======
        
        else {
            vector<vector<string> > board;
            for (int i = 0; i < sizes; i++) {
              vector<string> row;
>>>>>>> fbbd9ae3a753aa32a2d420f07a84d43fb393df10
                for (int j = 0; j < sizes; j++) {
                    if (i == 0 || i == sizes - 1) {
                        row.push_back(border);
                    }
                    else  if (j == 0 || j == sizes - 1) {
                        row.push_back(border);
                    }
                    else if (j < sizes - 1) {
                        //char value that gets added
                        string spot;
<<<<<<< HEAD
                        int pathOrBorder = (rand() % 3) + 1;
=======
                        int pathOrBorder = (rand() % 2) + 1;
>>>>>>> fbbd9ae3a753aa32a2d420f07a84d43fb393df10
                        if (pathOrBorder == 1) {
                            row.push_back(border);
                        }
                        else {
<<<<<<< HEAD
                            row.push_back(path);
=======
                             row.push_back(path);
>>>>>>> fbbd9ae3a753aa32a2d420f07a84d43fb393df10
                        }

                    }


                }
<<<<<<< HEAD
                board.push_back(row);
            }
            // assigns an enterance and exit value 
            // cant be on top or bottom row
            int randomEnterance =1+ ( rand() % sizes);
            int randomExit =1 + (rand() % sizes);
            board[randomEnterance][0] = path;
            board[randomExit][sizes - 1] = path;
=======
              board.push_back(row);
            }
          // assigns an enterance and exit value
          int randomEnterance = rand() % sizes;
          int randomExit = rand() % sizes;
          board[randomEnterance][0] = path;
          board[randomExit][sizes - 1] = path;
>>>>>>> fbbd9ae3a753aa32a2d420f07a84d43fb393df10
            mazeMade = board;
        }
    }


    void print(vector<vector<string> > maze) {
        string mazeOut = "";
        for (int i = 0; i < maze.size(); i++) {
            for (int j = 0; j < maze[i].size(); j++) {
                if (j == maze[i].size() - 1) {
                    cout << (maze[i][j]) << endl;
                }
                else {
                    cout << (maze[i][j]) + " ";
                }
            }
        }
    }
};

int main() {
    static int inputNum;
<<<<<<< HEAD
    cout << "Enter a number to make the maze (between 3 and 40, because 40 is the largest size availble in puTTy terminal)" << endl;
=======
    cout << "Enter a number to make the maze (between 3 and 40)" << endl;
>>>>>>> fbbd9ae3a753aa32a2d420f07a84d43fb393df10
    cin >> (inputNum);
    MazeGenerator first;
    first.border = "#";
    first.path = "-";
    first.mazeGenerator(inputNum);
    first.print(first.mazeMade);

<<<<<<< HEAD
    cout << endl;
    cout << endl;
    cout << endl;
    MazeGenerator second;
    second.border = "#";
    second.path = "-";
    second.mazeGenerator(40);
    second.print(second.mazeMade);
    cout << endl;
    cout << endl;
    cout << endl;
=======
  cout<<endl;
  cout<<endl;
    cout<<endl;
    MazeGenerator second;
    second.border = "#";
    second.path = "-";
    second.mazeGenerator(25);
    second.print(second.mazeMade);
cout<<endl;
  cout<<endl;
  cout<<endl;
>>>>>>> fbbd9ae3a753aa32a2d420f07a84d43fb393df10
    MazeGenerator third;
    third.border = "#";
    third.path = "-";
    third.mazeGenerator(35);
    third.print(third.mazeMade);
<<<<<<< HEAD
    cout << endl;
    cout << endl;
    cout << endl;
    MazeGenerator fourth;
    fourth.border = "#";
    fourth.path = "-";
    fourth.mazeGenerator(25);
    fourth.print(fourth.mazeMade);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "This doesn't make a good make pretty much ever. I can change the amount of borders spawen in the middle of the board, but that doesn't gaentee a valid path"<<endl;
    cout<<"Considering this ir random, its highly unlikely a valid maze is ever made with this approach. Would probably need to incoperate more algorithms"<<endl;
}
=======
cout<<endl;
  cout<<endl;
  cout<<endl;
   MazeGenerator fourth;
    fourth.border = "#";
    fourth.path = "-";
    fourth.mazeGenerator(40);
    fourth.print(fourth.mazeMade);
cout<<endl;
  cout<<endl;
  cout<<endl;

}
>>>>>>> fbbd9ae3a753aa32a2d420f07a84d43fb393df10
