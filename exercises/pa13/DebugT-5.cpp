// The goal of this debug execrice is to understand the concept of object
// slicing. Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

// Expected output -
// Name: tesla model Year: 2019
// Name: Hyundai model Year: 2020 Mileage: 23
// Name: Ford model Year: 2012 Miles driven: 20000
// Name: Ford model Year: 2017 Miles driven: 10000

/*
Most important changes:
1. Made the sedan and suv constructor make a car.
2. have the print methods in suv and sedan override the print() in car
3. specifiy that the assign in car is protected
4. have the assign method is suv be called via suv::assign(*b) to specifiy its
that one, and not the one in car. 
5. made getters for car name and car modelyear
  */

#include <iostream>

using namespace std;

class car {
private:
  string name;
  int modelYear;

protected:
  void assign(const car &c) {
    name = c.name;
    modelYear = c.modelYear;
  }

public:
  car(const string &n, const int my) : name(n), modelYear(my) {}

  virtual void print() const {
    cout << "Name: " << name << " model Year: " << modelYear << endl;
  }

  virtual const car &operator=(const car &c) {
    name = c.name;
    modelYear = c.modelYear;
    return *this;
  }

  string getName() const { return name; }
  int getModelYear() const { return modelYear; }
};

class sedan : public car {
private:
  int mileage;

public:
  sedan(const string &n, const int my, const int m) : car(n, my), mileage(m) {}

  virtual void print() const override {
    cout << "Name: " << getName() << " model Year: " << getModelYear()
         << " Mileage: " << mileage << endl;
  }
};

class suv : public car {

public:
  int miles;
  suv(const string &n, const int my, const int m) : car(n, my), miles(m) {}

  virtual void print() const override {
    cout << "Name: " << getName() << " model Year: " << getModelYear()
         << " Miles driven: " << miles << endl;
  }

  virtual const suv &operator=(const car c) {
    if (const suv *b = dynamic_cast<const suv *>(&c)) {
      suv::assign(*b);
    }
    return *this;
  }

protected:
  void assign(const suv &c) {
    car::assign(c);
    miles = c.miles;
  }
};

void printCarInfo(const car &c) { c.print(); }

int main() {
  car tesla = car("tesla", 2019);
  sedan hyundai = sedan("Hyundai", 2020, 23);
  suv ford = suv("Ford", 2012, 20000);

  printCarInfo(tesla);
  printCarInfo(hyundai);

  suv &ref = ford;
  printCarInfo(ref);
  suv ford2 = suv("Ford", 2017, 10000);
  ref = ford2;
  printCarInfo(ref);
  return 0;
}