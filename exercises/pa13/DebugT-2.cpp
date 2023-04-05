// Debug T-2
// Function template finds biggest of two or three objects. The function works
// on any data type which has greater than operator defined.

#include <iostream>
#include <string>
using namespace std;
template <class T> void findBiggest(T a, T b, T c) {
  T large = a;
  if (b > large)
    large = b;
  if (c > large)
    large = c;
  cout << "The largest of " << a << " " << b << " " << c << " is " << large
       << endl;
}
template <class T> void findBiggest(T a, T b) {
  T large = a;
  if (b > large) {
    large = b;
  }

  cout << "The larger of " << a << " " << b << " is " << large << endl;
}
class BankAccount {
  friend ostream &operator<<(ostream &, const BankAccount &);

private:
  string name;
  int amount;

public:
  BankAccount(string, int);
  bool operator>(const BankAccount &);
  bool operator<(const BankAccount &);
  bool operator==(const BankAccount &);
  string getName() const;
  int getAmount() const;
};

string BankAccount::getName() const { return name; }

int BankAccount::getAmount() const { return amount; }

BankAccount::BankAccount(string name, int amount) {
  BankAccount::name = name;
  BankAccount::amount = amount;
}
ostream &operator<<(ostream &out, const BankAccount &bh) {
  out << "Name " << bh.getName() << " Amount: " << bh.getAmount() << endl;
  return out;
}

bool BankAccount::operator>(const BankAccount &bh) {
  bool flag = false;
  if (amount > bh.amount)
    flag = true;
  return flag;
}

bool BankAccount::operator<(const BankAccount &bh) {
  bool flag = false;
  if (amount < bh.amount)
    flag = true;
  return flag;
}

bool BankAccount::operator==(const BankAccount &bh) {
  bool flag = false;
  if (amount == bh.amount)
    flag = true;
  return flag;
}

int main() {
  BankAccount bAA("A", 800);
  BankAccount bAB("B", 120);
  BankAccount bAC("C", 500);
  findBiggest(bAB, bAA);
  findBiggest(bAC, bAB);
  findBiggest(bAA, bAC);
  findBiggest(bAB, bAA, bAC);
  return 0;
}
