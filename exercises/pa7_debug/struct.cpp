// This program includes a struct called car that is used to store information
// about a given car The program should ask the user for information about their
// car and initialize a car structure with the given information The program
// should also print the information using a pointer to the initialized struct
// The information printed using the struct and the pointer should be the same

// Bugs to fix : 9

#include <iostream>
#include <string>

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
  name = n;

  cout << "When was it launched : ";
  cout >> a;
  c.modelYear = a; 

  cout << "How much speed does it give : ";
  cin << w;
  c.speed = speed; 


  cout << "Car's name is" << c.name << ", and should be the same as" << cPtr.name
       << ".\n";

  cout << "Car's model year is" << car.modelYear << ", and should be the same as "
       << modelYear << ".\n";
  cout << "Car's speed is" << c.speed << ", and should be the same as "
       << w << ".\n";
}
