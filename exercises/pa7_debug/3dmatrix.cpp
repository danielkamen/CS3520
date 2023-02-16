// Program to read 3-dimensional matrix and display the elements as 1x3N matrix
// TODO
// initize matrix using update_3d method (see comments below)
// display method must not be able to modify array elements (update the code as needed)
// display method must use a single loop/iterator to print the entire array with addresses
// display cannot use nested loops
// 

#include <iostream>
#include <cstdlib>

//error 1: forgot using namespace std
using namespace std;

// error 2/3 matrixs should take in size size size

void update_3d(double ***var, int length, int width, int height);
// error 4 make matrix const to not change data
void display_1d(const double ***var, int length, int width, int height);

//error 5: doesnt take in
int main() {
    //prompt the use to enter appropriate dimensions and initializ the matrix accordingly
    int length;
    cout << "Input the length of the lengthxWidthxHeight matrix: ";
    cin >> length;
    const int  l = length;
    int width;
    cout << "Input the width of the lengthxWidthxHeight matrix: ";
    cin >> width;
    const int w = width;
    int height;
    cout << "Input the length of the lengthxWidthxHeight matrix: ";
    cin >> height;
    const int h = height;

    double ***Matrix_3d = new double**[l];
    //initialize the array to non-zero values (use scanf or random numbers generator)
    update_3d(Matrix_3d, l, w, h);
    //display the values
    display_1d((const double ***)Matrix_3d, l, w , h);
    return 0;
}

void update_3d(double ***matrix, int length, int width, int height) {
    cout << "Entering 3N elements of the matrix:" << endl;
    for (int i = 0; i < length; i++) {
        // makes pointer to array of columns. 2nd dimensions
        matrix[i] = new double *[width];
        for (int j = 0; j < width; j++) {
            // adds the 1st
            matrix[i][j] = new double[height];
            for (int k = 0; k < height; k++) {
                int input = (rand() % 10) + 1;
                matrix[i][j][k] = input;
            }
        }
    }
}
//update as needed. 1 'for' loop only with 1 iterator to print all values with addresses
//must not be able to update the array.
//Share any observations.
void display_1d(const double ***matrix, int length, int width, int height) {
// how on earch can u do this without a triple for-loop???
for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < height; k++) {
 cout << "matrix[" << i << "][" << j << "][" << k << "] = " << &matrix[i][j][k] << "\tvalue = " << matrix[i][j][k] << endl;
}
}
}
}