#include <algorithm>
#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <cstdbool>

#ifndef BUG_HPP
#define BUG_HPP

using namespace std;
// forward decleration from stackoverflow lol this is cool
class Ant;
class DoodleBug;
class Queen;
class Worker;

// notes: how do i passs a vector into function?
// how do i want to handle the set?

class Bug {

protected:
  int x;
  int y;
  int it;
  char symbol;

public:
  Bug(int x, int y, int initalizedTime);

  virtual ~Bug(){};

  // these are different for each subclass

  // moves the bug
  virtual void move(vector<pair<int, int>> positions) = 0;
  // has the bug starved? different for different subtypes
  virtual bool starve() const = 0;
  // true if the bug can move, different for each subclass
  virtual vector<pair<int, int>> canMove(vector<Bug*> &bugs, int x, int y) const = 0;

  // can this bug breed right now?
 virtual bool canBreed() const = 0;

// breed this bug
virtual void breed(vector<Bug> &bugs) const  = 0;


// incremeneets the time
  static void operator++(Bug& bug);


  static bool compareBugs(const Bug* a, const Bug* b);

// Insert the new word into the vector
  static void addBug(vector<Bug*>& bugs, const Bug* newBug);

  /// these three are same implementation

  // does a bug exist at the givn coords?
  static bool bug_exists(vector<Bug*> &bugs, int x, int y);
  /// draws a bug
  static void draw_Bug(Bug *bug);
  // removes dead or eaten bugs
  static void remove_eaten_bug(vector<Bug*> &bugs, int x, int y);

  int getX() const;
  int getY() const;
  char getSymbol() const;
  int getInitalizedTime() const;
  void setX(int x);
  void setY(int y);


  static void display_bug_info(int x, int y);

};

class DoodleBug : public Bug {
protected:
  int timeSinceEating;

public:
  DoodleBug(int x, int y, int it);
  virtual ~DoodleBug();

  // moves the bug
  virtual void move(vector<pair<int, int>> positions) override;
  // has the bug starved? different for different subtypes
  virtual bool starve() const override;
  // true if the bug can move, different for each subclass
  virtual vector<pair<int, int>> canMove(vector<Bug*> &bugs, int x, int y) const override;

   // can this bug breed right now?
 virtual bool canBreed() const override;

// breed this bug
virtual void breed(vector<Bug*> &bugs) const override;
  
};

class Ant : public Bug {
public:
  Ant(int x, int y, int lifetime);
  virtual ~Ant();
};

class Queen : public Ant {
protected:
  int timeSinceLayedEggs;
  int timeSinceMadeQueen;
  int timeSinceMated;

public:
  Queen(int x, int y, int lifetime);
  virtual ~Queen();

  virtual void move(vector<pair<int, int>> positions) override;
  virtual bool starve() const override;
  virtual vector<pair<int, int>> canMove(vector<Bug*> &bugs, int x, int y) const override;
  virtual bool canBreed() const override;
  virtual void breed(vector<Bug*> &bugs) const override;

  // Queen specific behavior
  bool canMate() const;
  bool canMove() const;
 
};

class Worker : public Ant {
protected:
  int timeSinceMoved;

public:
  Worker(int x, int y, int it);
  virtual ~Worker();

  // female and male work the same here.
  virtual void move(vector<pair<int, int>> positions) override;
  virtual bool starve() const override;
  virtual vector<pair<int, int>> canMove(vector<Bug*> &bugs, int x, int y) const override;
  virtual bool canBreed() const override;
  virtual void breed(vector<Bug*> &bugs) const override;
};

class MaleAnt : public Worker {
public:
  MaleAnt(int x, int y, int it);
  virtual ~MaleAnt();
  virtual bool canBreed() const override;
  virtual void breed(vector<Bug*> &bugs) const override;
};





#endif