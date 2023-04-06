// Debug T-1
// Function template subtracts objects from each other. The function works on
// any object which has '-' opertor defined. Check for possible compiler errors,
// logical errors and rectify them Re-factor the code by adding few comments
// (make it readable) and provide list of most important fixes (in comments)

/*
Important fixes:
1. added getters for private feild calls
2. changed field name the  setValues method, which was the same as Person age feild. It set itself to itself, producing 0 every time.
I could also keep int age as a feild and instead declare Person::age = age; inside the method.
*/

#include <iostream>
#include <string>
using namespace std;
template <class T> T add(T x, T y) {
  T sum;
  sum = x + y;
  return sum;
}
class Person {
  friend ostream &operator<<(ostream &, const Person &);

private:
  string lastName;
  string firstName;
  int age;

public:
  void setValues(string, string, int);
  string getFirst() const;
  string getLast() const;
  int getAge() const;
  Person operator+(const Person &);
};

string Person::getFirst() const { return firstName; }

string Person::getLast() const { return lastName; }

int Person::getAge() const { return age; }

ostream &operator<<(ostream &out, const Person &per) {
  out << per.getFirst() << " " << per.getLast() << " " << per.getAge()
      << " years old" << endl;
  return out;
}
void Person::setValues(string last, string first, int ages) {
  lastName = last;
  firstName = first;
  age = ages;
}
Person Person::operator+(const Person &p) {
  Person temp;
  temp.age = p.getAge() + age;
  temp.firstName = "Sum";
  temp.lastName = "of age";
  return temp;
}

int main() {
  int a = 7, b = 26, c;
  double d = 39.25, e = 2.01, f;
  Person g, h, i;
  g.setValues("Mitchell", "Donald", 40);
  h.setValues("Clayton", "Rita", 35);
  c = add(a, b);
  f = add(d, e);
  i = add(g, h);
  cout << c << endl;
  cout << f << endl;
  cout << i << endl;
  return 0;
}
