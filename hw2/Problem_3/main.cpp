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
        int max = 100;
        if (sizes < min || sizes >= max) {
            cout << "Hey, you can't make a " << sizes << "x" << sizes << " maze. Call this method again with a size between" << min << " and " << max << "." << endl;
        }
        
        else {
            vector<vector<string> > board;
            for (int i = 0; i < sizes; i++) {
              vector<string> row;
                for (int j = 0; j < sizes; j++) {
                    if (i == 0) {
                        row.push_back("1");
                    }
                    else  if (j == sizes - 1) {
                        row.push_back("2");
                    }
                    else if (j < sizes - 1) {
                        //char value that gets added
                        string spot;
                        int pathOrBorder = (rand() % 2) + 1;
                        if (pathOrBorder == 1) {
                            row.push_back("3");
                        }
                        else {
                             row.push_back("4");
                        }

                    }


                }
              board.push_back(row);
            }
          board[8][8]="121314";
            mazeMade = board;
        }
    }


    void print(vector<vector<string> > maze) {
        string mazeOut = "";
        for (int i = 0; i < maze.size(); i++) {
            for (int j = 0; j < maze[i].size(); j++) {
                if (j == maze[i].size() - 1) {
                    cout << (maze[j][j]) + "\n" << endl;
                }
                else {
                    cout << (maze[j][j]) + " ";
                }
            }
        }
    }
};

int main() {
    static int inputNum;
    cout << "Enter a number to make the maze (between 3 and 100)" << endl;
    cin >> (inputNum);
    MazeGenerator first;
    first.border = "#";
    first.path = "-";
    first.mazeGenerator(inputNum);
    first.print(first.mazeMade);

}