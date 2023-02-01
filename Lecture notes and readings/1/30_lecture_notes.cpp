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

}



