/*
input validation:
input is what you expect it to be*/
#include <bitset>
#include <iostream>
#include <limits>
using namespace std;

int main() {
int x;
if (cin>>x) // EXTRACTION OPERATOR
    cout<<x<<endl;
    else
    cout<<"input error"<<endl; // INSERTION OPERATOR



/*
istream::operator>>
return type is an istream referance
another way of saying when u call cin>>x, compile converts that into a function call that looks like this: cin& operator>>(cin& , x)
                return cin referance  funtion name
*/
int y;
cin>>y;
bit


}