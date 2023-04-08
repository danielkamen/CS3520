#include "movie.hpp"

Movie::Movie(const Movie &other) : Book(other), director(other.director) {}

Movie::Movie(Movie &&other) noexcept
    : Book(move(other)), director(move(other.director)) {}

Movie &Movie::operator=(const Movie &other) {
  if (this != &other) {
    Book::operator=(other);
    director = other.director;
  }
  return *this;
}

Movie &Movie::operator=(Movie &&other) noexcept {
  if (this != &other) {
    Book::operator=(move(other));
    director = move(other.director);
  }
  return *this;
}

ostream &operator<<(ostream &out, const Movie &m) {
  out << m.getName() << ", " << m.getDirector()
      << ", " << m.getYear();
  return out;
}

bool Movie::operator==(const Movie &other) const {
  return (this->getName() == other.getName() &&
          this->getYear() == other.getYear());
}

bool Movie::operator!=(const Movie &other) const {
  return !(this->operator==(other));
}