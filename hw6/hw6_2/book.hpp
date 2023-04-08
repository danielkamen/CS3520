#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
  string name;
  int pubYear;

public:
  string getName() const;
  int getYear() const;
  Book(const string &n, int y) : name(n), pubYear(y) {}
  Book(const Book &other);
  Book(Book &&other) noexcept;
  Book &operator=(const Book &other);
  Book &operator=(Book &&other) noexcept;
  friend ostream &operator<<(ostream &, const Book &);
  bool operator==(const Book &other) const;
  bool operator!=(const Book &other) const;
  ~Book(){};
};

#endif