//This program allocated memory for an NxM integer array dynamicaly 
//The program then prints the 2D array in a matrix form using a combination of * and [] operators
//Note: You can't use ** or [][] for printing the values (use a combination of * and [] only.

//Number of bugs/errors : 6

#include <iostream>
#include <cstdlib>

//error 3 forgot this library
#include <stdio.h>
using namespace std;

int main() {
    int N = 3, M = 5;
    int i, j;
	// error 4 forogt * after sizeof(int)
    int** d_array = (int**)malloc(N * sizeof(int*)); 	//Allocating memory for 2D array (N rows)
    //error 1 no semicolon
    for (i = 0; i < N; i++) {
        d_array[i] = (int*)malloc(M * sizeof(int*)); 
         //Allocating memory for each row with M columns)
    }
    //Initializing 2D array using [ ][ ] notation
    printf("Initializing array values! \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            // error 2, missed a * and semi colon. 
			// error 5 bad logic
            *(d_array[i] + j) = i * 3 + j + 1;
        }
    }
    //Accessing 2D array using a combination of * and [] notation
    printf("\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << *(d_array[i] + j)<<" ";
        }
        cout << "\n";
    }

    //Deallocating 2D array
    for (i = 0; i < N; i++) {
		// error 6, bad logic
        free(d_array[i]);
	}
    free(d_array);
}
