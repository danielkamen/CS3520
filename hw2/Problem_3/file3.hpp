#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class MazeGenerator {
public:
    char border;
    char path;
    // generates a pointer to the array 
    int* mazeGenerator(int size) {
        // min path is 3, and 100 is used to just not make a super big maze for this assignment
        int min = 3;
        int max = 100;
        if (size < min || size <= max) {
            cout << "Hey, you can't make a " << size << "x" << size << " maze. Call this method again with a size between" << min << " and " << max << "." << endl;
        }
        else {
            vector<vector<char>> maze;
            // flags for the enterance and exit
            bool isExitMade = false;
            bool isEntranceMade = false;
            // random value to detemine row of enterance
            int enterRow = rand() % size;
            // random value to determine tow of exit
            int exitRow = rand() % size;
            for (int i = 0; i < size; i++) {
                vector<char> row;
                for (int j = 0; j < size; j++) {
                    //case for adding entrance and exit
                    if ((i == enterRow && j == 0) || (i == exitRow && j == size - 1)) {
                        row.push_back(MazeGenerator::path);
                        //case for every other border
                    }
                    else if ((i == 0 || j == 0 || i == size - 1 || j == size - 1)) {
                        row.push_back(MazeGenerator::border);
                        
                    }
                    // case for non-border spots
                    else {
                        //char value that gets added
                        char spot;
                        int pathOrBorder = rand() % 2;
                        if (pathOrBorder == 0) {
                            spot = MazeGenerator::border;
                        }
                        else {
                            spot = MazeGenerator::path;
                        }
                        row.push_back(spot);
                    }
                }
            }
        }
    }
};