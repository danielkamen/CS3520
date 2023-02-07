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

        else { 

            // initialzes an empty board vector
            vector<vector<string> > board;
            for (int i = 0; i < sizes; i++) {
                // initalizes an empty row  vector
                vector<string> row;
                for (int j = 0; j < sizes; j++) {
                    // if its the first or last row
                    if (i == 0 || i == sizes - 1) {
                        row.push_back(border);
                    }
                    // if its the first or last column
                    else  if (j == 0 || j == sizes - 1) {
                        row.push_back(border);
                    }
                    // if its anything inbetween the first and last column
                    else if (j < sizes - 1 && j < 0) {
                        //char value that gets added
                        string spot;
                        // rand value to detemine if a path or border is added
                        int pathOrBorder = (rand() % 2) + 1;
                        if (pathOrBorder == 1) {
                            row.push_back(border);
                        }
                        else {
                            row.push_back(path);
                        }

                    }


                }
                board.push_back(row);
            }
            // assigns an enterance and exit value
            int randomEnterance = rand() % sizes;
            int randomExit = rand() % sizes;
            board[randomEnterance][0] = path;
            board[randomExit][sizes - 1] = path;
            mazeMade = board;
        }
    }


    // prints each value in the vector, and adds a space between items in a row
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
    cout << "Enter a number to make the maze (between 3 and 40)" << endl;
    cin >> (inputNum);
    // initalizer for the mazes
    MazeGenerator first;
    first.border = "#";
    first.path = "-";
    first.mazeGenerator(inputNum);
    first.print(first.mazeMade);

    cout << endl;
    cout << endl;
    cout << endl;
    MazeGenerator second;
    second.border = "#";
    second.path = "-";
    second.mazeGenerator(25);
    second.print(second.mazeMade);
    cout << endl;
    cout << endl;
    cout << endl;
    MazeGenerator third;
    third.border = "#";
    third.path = "-";
    third.mazeGenerator(35);
    third.print(third.mazeMade);
    cout << endl;
    cout << endl;
    cout << endl;
    MazeGenerator fourth;
    fourth.border = "#";
    fourth.path = "-";
    fourth.mazeGenerator(40);
    fourth.print(fourth.mazeMade);
    cout << endl;
    cout << endl;
    cout << endl;
	cout<<"This doesnt make a good maze pretty much ever. Theres no garentee a valid path is made"<<endl;

}
