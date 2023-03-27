#ifndef BUG_HPP
#define BUG_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

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
  virtual void move() = 0;
  // has the bug starved? different for different subtypes
  virtual bool starve() const = 0;
  // true if the bug can move, different for each subclass
  virtual bool canMove(vector<Bug> &bugs, int x, int y) const = 0;

  /// these three are same implementation

  // does a bug exist at the givn coords?
  static bool bug_exists(vector<Bug> &bugs, int x, int y);
  /// draws a bug
  static void draw_Bug(Bug *bug);
  // removes dead or eaten bugs
  static void remove_eaten_bug(vector<Bug> &bugs, int x, int y);

  int getX() const;
  int getY() const;
  int getInitalizedTime() const;
  void setX(int x);
  void setY(int y);
};

class DoodleBug : public Bug {
protected:
  int timeSinceEating;

public:
  DoodleBug(int x, int y, int it) : Bug(x, y, it) {
    symbol = 'X';
    timeSinceEating = 0;
  };
  virtual ~DoodleBug();

  // moves the bug
  virtual void move() override;
  // has the bug starved? different for different subtypes
  virtual bool starve() const override;
  // true if the bug can move, different for each subclass
  virtual bool canMove(vector<Bug> &bugs, int x, int y) const override;
};

class Ant : public Bug {
public:
  Ant(int x, int y, int lifetime) : Bug(x, y, lifetime){};
  virtual ~Ant();
};

class Queen : public Ant {
protected:
  int timeSinceLayedEggs;
  int timeSinceMadeQueen;
  int timeSinceMated;

public:
  Queen(int x, int y, int lifetime) : Ant(x, y, lifetime) {
    symbol = 'Q';
    timeSinceMadeQueen = 0;
    timeSinceLayedEggs = 0;
    timeSinceMated = 0;
  };
  virtual ~Queen();

  virtual void move() override;
  virtual bool starve() const override;
  virtual bool canMove(vector<Bug> &bugs, int x, int y) const override;

  // Queen specific behavior
  bool canMate() const;
  bool canMove() const;
  bool canBreed() const;
  void breed(vector<Bug> &bugs) const;
};

class Worker : public Ant {
protected:
  int timeSinceMoved;

public:
  Worker(int x, int y, int it) : Ant(x, y, it) {
    symbol = 'w';
    timeSinceMoved = 0;
  };
  virtual ~Worker();

  // female and male work the same here.
  virtual void move() override;
  virtual bool starve() const override;
  virtual bool canMove(vector<Bug> &bugs, int x, int y) const override;
};

class MaleAnt : public Worker {
public:
  MaleAnt(int x, int y, int it) : Worker(x, y, it) { symbol = 'o'; };
  virtual ~MaleAnt();
};