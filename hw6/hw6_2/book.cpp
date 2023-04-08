#include "book.hpp"
#include <iostream>
#include <string>


using namespace std;


string Book::getName() const {
    return name;
}
    int Book::getYear() const {
        return pubYear;
    }

Book::Book(const Book &other) : name(other.getName()), pubYear(other.getYear()) {}

Book::Book(Book &&other) noexcept
    : name(move(other.getName())), pubYear(other.getYear()) {}

Book &Book::operator=(const Book &other) {
  if (this != &other) {
    name = other.getName();
    pubYear = other.getYear();
  }
  return *this;
}

Book &Book::operator=(Book &&other) noexcept {
  if (this != &other) {
    name = move(other.getName());
    pubYear = other.getYear();
  }
  return *this;
}

ostream &operator<<(ostream &out, const Book &b) {
  out << b.getName() << ", " << b.getYear();
  return out;
}

// overloads == to only compare books
  bool Book::operator==(const Book &other) const {
    return this->name == other.getName() &&
    this->pubYear == other.getYear();
  }
  // overloads =! to only compare
  bool Book::operator!=(const Book &other) const {
   return this->name != other.getName() ||
    this->pubYear != other.getYear();
  }


