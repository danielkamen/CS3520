// This program includes a struct called car that is used to store information
// about a given car The program should ask the user for information about their
// car and initialize a car structure with the given information The program
// should also print the information using a pointer to the initialized struct
// The information printed using the struct and the pointer should be the same

// Bugs to fix : 9

#include <iostream>
#include <string>

// error 1: forgot namespace std -------------------------------------------------------
using namespace std;

struct car {
  char *name;
  int modelYear;
  float speed;
};

int main(void) {
  char n[20];
  int a;
  float w;

  struct car c;
  car *cPtr = &c;

  cout << "What is your favorite car's name: ";
  cin >> n;
  // error 2, didnt have a c. classifer in front of name. ------------------------------
  c.name = n;

  cout<<endl; 
  // added this to break it up visually.

  cout << "When was it launched : ";
  // error 3: didnt have a cin _---------------------------------------------------------
  cin >> a;
  c.modelYear = a; 


 cout<<endl; 
  // added this to break it up visually.

  cout << "How much speed does it give : ";
  // error 4: arrows pointing the wrong way --------------------------------------------
  cin >> w;
  // error 5: c.speed should equal w not speed -----------------------------------------
  c.speed = w; 


// error 6: didndt dereferance cPt
  cout << "Car's name is" << c.name << ", and should be the same as" << cPtr->name
       << ".\n";

        cout<<endl; 
  // added this to break it up visually.

// error 7: refered to car.modelyear instead of c.modelYear
  cout << "Car's model year is" << c.modelYear << ", and should be the same as "
  //error 8: didnt call the cPtr at all, which should also be dereferanced ---------------
       << cPtr->modelYear << ".\n";

        cout<<endl; 
  // added this to break it up visually.

  
  cout << "Car's speed is" << c.speed << ", and should be the same as "
  // error 9: w is jsut not right, needs cPtr->speed to go from pointer to variabler -----
       << cPtr->speed << ".\n";
}
