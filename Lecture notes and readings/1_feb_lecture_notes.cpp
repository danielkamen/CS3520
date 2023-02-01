// arrays vectors

#include <iostream>
#include <vector>

using namespace std;

int main() {

int arr[5][5] = {{1,2,3,4,5}, {6,7,8}};

for(int i = 0; i<5; ++i) {
    for(int j = 0; j<5; ++j) {
        cout<<arr[i][j]<< " ";
    cout<<endl;
    }
}


// when doing for loop with &arr[i][j], the memory of each value is printed
// the address of the 1st item in second row is 4 after last item i frist row
for(int i = 0; i<5; ++i) {
    for(int j = 0; j<5; ++j) {
        cout<<&arr[i][j]<< " ";
    cout<<endl;
    }
}

cout<<arr<<endl; // start of 2d array

cout<<&arr[0][0]<< endl; // start of 2d array

cout<<&arr[0][5]<<endl; // start of second row, NO INDEX OUT OF BOUNDS

/*
1. be careful with indecies, no index out of bounds exception
2. 2d array, and single bracket, ur accesing the first elemn of row
*/


// enhanced for loop
// one thing to account for: inner for loop will read each row
// expects the row to be the address of the beginning of that row
// first type of outter loop MUST BE &row
for(auto &row: arr) {
    for(auto e: row) {
        cout<<e<< " ";
    cout<<endl;
    }
}
/*
OR:
for(auto& row: arr) {
    for(int e: row) {
        cout<<e<< " ";
    cout<<endl;
    }
}
*/

}