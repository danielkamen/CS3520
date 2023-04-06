#include <cstring>
#include <iostream>
#include <memory>
using namespace std;

class MyString {
  unique_ptr<char[]> str;

public:
  // Default Constructor
  MyString() : str(new char[1]) {
    str[0] = '\0';
    cout << "Default Constructor" << endl;
  }

  // constructor with a char argument
  MyString(unique_ptr<char[]> &val) : str(move(val)) {
    if (val == nullptr) {
      cout << "The given string is: " << str.get() << endl;
      str.reset(new char[1]);
      str[0] = '\0';
    }
  }

  // constructor that copys its source
  MyString(const MyString &source) {
    int length = strlen(source.str.get()) + 1;
    str.reset(new char[length]);
    strcpy(str.get(), source.str.get());
    str[length - 1] = '\0';
  }

  //*******************************************************
  // THIS WORKS ON REPLIT BUT NOT ON KHOURY SERVER
  // Move Constructor
  MyString(MyString &&source) { str = move(source.str); }
  //******************************************************

  // Destructor
  ~MyString() = default;
};

int main(void) {

  cout << "Start!" << endl;
  unique_ptr<MyString> a(new MyString());
  unique_ptr<char[]> hello(new char[6]{'H', 'e', 'l', 'l', 'o', '\0'});
  unique_ptr<MyString> b(new MyString(hello));
  
  
  // THIS WORKS ON REPLIT BUT NOT ON KHOURY SERVER
  //unique_ptr<char[]> hello2(new char[7]{"Hello2"});
  // THIS WORKS ON REPLIT BUT NOT ON KHOURY SERVER
  //MyString c{MyString{hello2}};

  unique_ptr<char[]> world(new char[6]{'W', 'o', 'r', 'l', 'd', '\0'});
  unique_ptr<MyString> d{new MyString(world)};

  cout << "Bye" << endl;
}
