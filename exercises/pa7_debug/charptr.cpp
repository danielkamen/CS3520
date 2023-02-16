//This program should read any string (including spaces) from the user and print it using a character pointer
//The program is setup to use pointer offset notation to get each character of the string

//Number of bugs/errors : 8

// error 1: should be cstdio
// error 2: didnt include iostream
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

// error 3: shouldnt take in a void
// error 4: should return an int
int main() {
    char s[20];
    // error 5: forgot to make cPtr a pointer, missing *
    char *cPtr;

  
    cout << "Enter ur stuff under 20 characters ";
    cin.getline(s, 20);
     cPtr = s;
  cout<<endl;
  // error 6: fbad logic here
  int offset = 0;
  // error 7: bad logic again
    while(*(cPtr + offset) != '\0'){
      // error 8: bad logic
        cout<<*(cPtr + offset);
      offset++;
    }
  cout<<"\n";
  return 0;
}
