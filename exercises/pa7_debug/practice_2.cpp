// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.

// Number of errors/bugs = 10

#include <iostream>
using namespace std;

// error 8 tajes in an int matrix not double matrix
void display(int Matrix[3][3],int size); 

// error 1: needs to be int main()
int main() {
  //error 2: had to make size const to declare it in size
	const int size=3; 
  // error 10: has to be size x size, not 4x4
	int Matrix[size][size]; 
  // errors 3: cin arrows in wrong direction
  // error 4 cant have endl in cin line
	cout<<"Enter 9 elements of the matrix:";

  // error 5: had to declare i as int
	for (int i = 0; i < size; i++) 
    {
      // error 6: int j = 0 has to be in loop
      for (int j = 0; j < size; j++){
        int input;
        cin>> input;
       Matrix[j][i] = input; 
      }
    }
    // error 9: cant take in a memory address
	display(Matrix,3);
	return 0;
}

// error 8: needs to be an int not float
void display(int Matrix[3][3], int size) { 
	for (int i = 0; i < size ; i++) {
    // shouldn increment by j++ not i++
		for (int j = 0; j < size; j++) 
        {
            cout<<Matrix[i][j]<<", ";
        }
        cout<<endl;
	}    
}
