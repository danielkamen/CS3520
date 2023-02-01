//CONST saves memory


// ARRAYS
#include <iostream>
#include <vector>
using namespace std;


int main() {

// static allocation of memory, when we know size at compile time
// fixed size
// COMPILER GARENTEES THIS WILL BE STORED IN MEMORY IN CONTIGUOUS MEMORY.
// think of it like this: memory is a box: array items will be stored next to each other [][1][2][3][4][5][][]
int arr[5] = {1,2,3,4,5};

// dynamic allocation, new memory 
//int arr[ ] = {1,2,3,4,5, 66};
for(int i = 0; i<5; ++i)
    cout<<arr[i]<<" ";
    cout<<endl;

/*
    for(auto e:arr)  // advanced for-loop
        cout<<e<<" ";
    cout<<endl;
*/

// name of array, is the memeory address of the first element in the array
cout<<arr << " "<< &arr<< " "<< &arr[0]<<endl<<&arr[1]<<" "<<&arr[4]<<" "<<&arr[5]<<endl;

/*
NO INDEX OUT OF BOUNDS
if it goes over, it will return the value of next memory address

*/



double arrd[6] = {1,2,3,4,5, 6};
for(int i = 0; i<5; ++i)
    cout<<arrd[i]<<" ";
    cout<<endl;
// name of array, is the memeory address of the first element in the array
cout<<arrd << " "<< &arrd<< " "<< &arrd[0]<<endl<<&arrd[1]<<" "<<&arrd[4]<<" "<<&arrd[6]<<endl;


//these two lines do same thing. non-commented line is whats typically done
//int * ptr = &arr[0];
// can change where pointer points to here.
int * ptr = arr;
cout<<"where is pointer: "<<&ptr <<endl
  <<"What is in pointer: "<<ptr <<endl
  <<"what is the value (not mememory value) in varibale that pointer POINTs to: "<<*ptr<<endl;
  // this is the same, but arr is a contsant pointer, fixed, read-only variable
  cout<<"where is pointer: "<<&arr <<endl
  <<"What is in pointer: "<<arr <<endl
  <<"what is the value (not mememory value) in varibale that pointer POINTs to: "<<*arr<<endl;


/*
POINTER ARITHMATICS
*/
// What about:
cout<<ptr<<", "<<ptr+1<<endl;
// off by 4 bits, incremented by 4 bites. int - 4 bytes
// this points the the next item in the ARRAY

double * ptrd = arrd;
// what about:
cout<<ptrd<<", "<<ptrd + 1<<endl;
// off by 8 bits, incremented by 8 bites, double - 8 bytes
























}


