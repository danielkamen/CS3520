//This program should read any string (including spaces) from the user and print it using a character pointer
//The program is setup to use pointer offset notation to get each character of the string

//Number of bugs/errors : 8

#include <stdio>
#include <string>

using namespace std;

void main(void){
    char s[20];
    char cPtr;
    cin>>s;
    cPtr = s;
    while(cPtr-- == '\0'){
        cout<<cPtr++;
    }
  cout<<"\n";
  return 0;
}
