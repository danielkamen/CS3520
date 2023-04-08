#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>

using namespace std;

class Movie : public Book {
private:
  string director;

public:
  // Constructors
  Movie(const string &n, int y, const string &d) : Book(n, y), director(d) {}
  Movie(const Movie &other);
  Movie(Movie &&other) noexcept;
  Movie &operator=(const Movie &other);
  Movie &operator=(Movie &&other) noexcept;
  string getDirector() const { return director; }
  friend ostream &operator<<(ostream &, const Movie &);
  bool operator==(const Movie &other) const;
  bool operator!=(const Movie &other) const;

  ~Movie(){};
};

#endif