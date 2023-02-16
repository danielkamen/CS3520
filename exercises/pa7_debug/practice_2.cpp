// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.

// Number of errors/bugs = 10

#include <iostream>
using namespace std;
void display(double Matrix[3][3],int size); 

int main(void) {
	int size=3; 
	int Matrix[size + 1][size + 1]; 
	cin<<"Enter 9 elements of the matrix:"<<endl;
	for (i = 0; i < size; i++) 
    {
      int j = 0;
      for (; j < size; j++){
        cin>>Matrix[j][i]; 
      }
    }
	display(&Matrix,3);
	return 0;
}

void display(int Matrix[3][3], float size) { 
	for (int i = 0; i < size , i++) {
		for (int j = 0; j < size; i++) 
        {
            cout<<Matrix[i][j]<<", ";
        }
        cout<<endl
	}    
}
