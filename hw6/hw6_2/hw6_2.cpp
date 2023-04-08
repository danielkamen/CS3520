
#include "book.cpp"
#include "movie.cpp"
#include "template.hpp"
#include <string>

using namespace std;

int main() {
  
    // ----------------------------------------------------------------
    vector<int> ints = {78, 86, 45, 23, 83, 19, 104};
    // construcotr
    Repository<int> repoInts(ints);

    // copy constructor
    Repository<int> repoIntsCopy(repoInts);
    repoIntsCopy.printList();

    // move constructor
    Repository<int> repoIntsMoved = move(repoInts);
    repoIntsMoved.printList();

    // copy assignment operator
    Repository<int> repoIntsCopy2 = ints;
    repoIntsCopy2.printList();

    // move assignment operator
    Repository<int> repoIntsMoved2 = move(repoIntsCopy);
    repoIntsMoved2.printList();

    // adding 1 item
    repoInts.add(999);
    repoInts.printList();
    // adding an existing item
    repoInts.add(19);
    repoInts.printList();

    cout << endl;
    cout << "tried adding same set again" << endl;
    // adding a vector of items that already exist
    repoInts.add(ints);
    cout << endl;
    ints = {888, 777, 555, 333, 222, 192};
    // adding a vector of items that dont exist
    repoInts.add(ints);

    // removing an item
    repoInts.remove(999);
    // removing an item that doesnt exist
    repoInts.remove(2);

    repoInts.printList();

    // removing multiple items
    repoInts.remove(ints);

    // determine the order/postion of items
    repoInts.contains(104);
    repoInts.contains(39);

    // ---------------------------------------------------------
    vector<string> words = {"apple", "bottom", "jearns", "boots", "with"};
    // construcotr
    Repository<string> repoWords(words);

    // copy constructor
    Repository<string> repoWordsCopy(repoWords);
    repoWordsCopy.printList();

    // move constructor
    Repository<string> repoWordsMoved = move(repoWords);
    repoWordsMoved.printList();

    // copy assignment operator
    Repository<string> repoWordsCopy2 = words;
    cout << "Copy Assignment Construtor" << endl;
    repoWordsCopy2.printList();

    // move assignment operator
    Repository<string> repoWordsMoved2 = move(repoWordsCopy);
    cout << "Move Assignment Construtor" << endl;
    repoWordsMoved2.printList();
    // adding 1 item
    repoWords.add("999");
    repoWords.printList();
    // adding an existing item
    repoWords.add("jearns");
    repoWords.printList();

    cout << endl;
    cout << "tried adding same set again" << endl;
    // adding a vector of items that already exist
    repoWords.add(words);
    cout << endl;
    words = {"bliss", "energy", "lummy", "buaint", "sheesh"};
    // adding a vector of items that dont exist
    repoWords.add(words);

    // removing an item
    repoWords.remove("999");
    // removing an item that doesnt exist
    repoWords.remove("helloNTC");

    repoWords.printList();

    // removing multiple items
    repoWords.remove(words);

    // determine the order/postion of items
    repoWords.contains("boots");
    repoWords.contains("sunburn");
  
  //-----------------------------------------------------

  Book b1("Catcher rye", 1900);
  Book b2("Kill a Mockingbird", 1800);
  Book b3("Huck finn", 1700);

  vector<Book> books = {b1, b2, b3};
  // Constructor
  Repository<Book> repoBooks(books);
  repoBooks.printList();
  // Copy Constructor
  Repository<Book> repoBooksCopy(repoBooks);
  repoBooksCopy.printList();
  // Move Constructor
  Repository<Book> repoBooksMoved = move(repoBooks);
  repoBooksMoved.printList();
  // Copy Assignment Operator
  Repository<Book> repoBooksCopy2 = books;
  cout << "Copy Assignment Constructor" << endl;
  repoBooksCopy2.printList();
  // Move Assignment Operator
  Repository<Book> repoBooksMoved2 = move(repoBooksCopy);
  cout << "Move Assignment Constructor" << endl;
  repoBooksMoved2.printList();
  // Adding a book
  Book b4("1984", 1949);
  repoBooks.add(b4);
  repoBooks.printList();
  // Adding an existing book
  repoBooks.add(b3);
  repoBooks.printList();
  // Adding a vector of items that already exist
  repoBooks.add(books);
  // Adding a vector of items that don't exist
  vector<Book> newBooks = {Book("Book", 1999), Book("Brave New World", 1932)};
  repoBooks.add(newBooks);
  repoBooks.printList();
  // Removing a book
  repoBooks.remove(b4);
  repoBooks.printList();
  // Removing a book that doesn't exist
  Book b5("The Lord of the Ring", 1992);
  repoBooks.remove(b5);
  // Removing multiple books
  vector<Book> toRemove = {b1, b2};
  repoBooks.remove(toRemove);
  repoBooks.printList();
  // Determine the order/position of books
  repoBooks.contains(b3);
  repoBooks.contains(b5);

  //----------------------------------------------------------
  Movie movie1("The Shawshank Redemption", 1994, "Frank");
  Movie movie2("The Godfather", 1972, "Francis");
  Movie movie3("The Dark Knight", 2008, "Christopher Nolan");

  // test the copy constructor
  Movie movie4 = movie1;
  cout << movie4 << endl;

  // test the move constructor
  Movie movie5 = move(movie2);
  cout << movie5 << endl;

  // test the copy assignment operator
  Movie movie6("The Lord of the Rings", 2001, "Peter Jackson");
  movie6 = movie3;
  cout << movie6 << endl;

  // test the move assignment operator
  Movie movie7("Pulp Fiction", 1994, "Quentin Tarantino");
  movie7 = move(movie4);
  cout << movie7 << endl;

  // add some movies to a Repository
  Repository<Movie> movieRepo({movie1, movie2, movie3});
  movieRepo.add(movie4);
  movieRepo.add(movie5);
  movieRepo.add(movie6);
  movieRepo.add(movie7);
  movieRepo.printList();

  // test removing a movie
  movieRepo.remove(movie3);
  movieRepo.printList();
  return 0;
}