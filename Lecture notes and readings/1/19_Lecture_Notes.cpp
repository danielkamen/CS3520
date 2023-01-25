/*
topics: for loops, while loops, do while loops
counted for loops pretty similar to what i learned in funedies 2
strings / string library
https://cplusplus.com/reference/string/
*/
int main() {
    count << "Hi!" << endl;

    srand(time(nullptr));
    for (int i =0; i < 25; i++) {

    }
}

/*
c++ string library --- IMPORTANT FOR HW1
learn the methods in it


length
*/

int main() {
    string str ("Test string"); // 11 characters
    for(unsigned i = 0; i<str.length(); ++i) {
        count<<str.at(i)<< " "; 
        // T e s t  s t r i n g
    }
    cout <<endl;
    for(unsigned i = 0; i<str.length(); ++i) {
        cout << str[i]<< " ";
    }
    // T.e.s.t. . s.t.r.i.n.g.
    cout <<endl;

    for(char oneChar :str)
        cout << oneChar << ",";
        // T,e,s,t, ,s,t,r,i,n,g,
    cout <<endl;

// auto - asks complier to figure out what type is variable
 for(auto oneChar :str)
        cout << oneChar << ",";
        // T,e,s,t, ,s,t,r,i,n,g,
    cout <<endl;

}


// one little point about for loops SOMETHINGS NEW
for(int i =10, int j =5;i>0; i--, j++) {}
// can use this for truth table and boolean logic
// && 
// ||
//Xor -> 1 when conditions are not the same ->0 when the same
// short circuiting -- false || false ||true ||false ---- stops at first true and doesnt eval the rest

char cc;
cin>>cc;
    switch(cc) { // works when its an int or char
    case 'a' : // no break makes the cout below to cover both cases. useful for accepting either case 
    case 'A' : cout<<"A or a"<<endl; break;
    case 'b' : cout<<"b"<<endl; break;
    default :  cout<<"other"<<endl;


/*
substring method
find method ****USEFUL HINT FOR ASSINGMENT****
replace method **USEFUL HINT FOR ASSIGNMENT****

*/


// compare: compare two strings
// uses dictionary ordering
// word 1 comes before word 2, returns negative
// word 1 comes after word 2, returns positive
// QUESTION: does captial or lowecase matter????????????????
//--------------------------------------------------------------

// Structures:
#include <iostream>
#include <limits>
using namespace std;

// this is outside of main()
// structs end with ;
// can have variables
// can have functions
// all memebers of stuct are default public
struct Student {
    int std_id;
    string std_name;
    void print() {
        cout<< std_name << " has id:"<< std_id <<endl;
    }
};

// to make it a class
// all members of class are default private
class Student {
    public: int std_id;
    string std_name;
    void print() {
        cout<< std_name << " has id:"<< std_id <<endl;
    }
};



int main() {
    Student first; // instane of a struct type student
    first.std.id = 100;
    first.std_name ="d";
    Student second{222, "kelly"};
    //cout<<first.std_name<< "has id:"<< first.std_id <<endl;
    first.print();
        second.print();

}