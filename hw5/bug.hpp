#include <algorithm>
#include <cstdbool>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

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

public:
  int x;
  int y;
  int it;
  char symbol;
  int starveTicks;

public:
  Bug(int x, int y, int initalizedTime);

  virtual ~Bug(){};

  // these are different for each subclass

  // moves the bug and needs info about other bug positons, doodlebug
  virtual void move(Bug *bug, vector<Bug *> &bugs,
                    vector<pair<int, int>> positions) = 0;

  // has the bug starved? different for different subtypes
  virtual bool starve() const = 0;
  // true if the bug can move, different for each subclass
  virtual vector<pair<int, int>> canMove(vector<Bug *> &bugs, int x,
                                         int y) const = 0;

  // can this bug breed right now?
  virtual bool canBreed() const = 0;

  // breed this bug
  virtual void breed(vector<Bug *> &bugs) = 0;

  static void incTime(Bug *bug);
  static void incStarve(Bug *bug);

  static bool compareBugs(const Bug *a, const Bug *b);

  // Insert the new word into the vector
  static void addBug(vector<Bug *> &bugs, Bug *newBug);
  /// these three are same implementation

  // does a bug exist at the givn coords?
  static bool bug_exists(vector<Bug *> &bugs, int x, int y);
  // bounces the bug
  static void bounce(int newPx, int newPy, int oldPx, int oldPy, Bug *bug,
                     vector<Bug *> bugs);

  // type at coord

  static char typeAtCoord(vector<Bug *> &bugs, int x, int y);

  /// draws a bug
  static void draw_Bug(Bug *bug);
  // removes dead or eaten bugs
  static void remove_eaten_bug(vector<Bug *> &bugs, int x, int y);

  int getX() const;
  int getY() const;
  char getSymbol() const;
  int getInitalizedTime() const;
  int getStarveTicks() const;
  void setX(int x);
  void setY(int y);
  void resetStarveTicks();

  static void display_bug_info(int count, int x, int y, Bug *bug);
};

class DoodleBug : public Bug {

public:
  DoodleBug(int x, int y, int it);
  virtual ~DoodleBug();

  // moves the bug, prioritizes positions where a bug exists
  virtual void move(Bug *db, vector<Bug *> &bugs,
                    vector<pair<int, int>> positions) override;
  // has the bug starved? different for different subtypes
  virtual bool starve() const override;
  // true if the bug can move, different for each subclass
  virtual vector<pair<int, int>> canMove(vector<Bug *> &bugs, int x,
                                         int y) const override;

  // can this bug breed right now?
  virtual bool canBreed() const override;

  // breed this bug
  virtual void breed(vector<Bug *> &bugs) override;
};

class Ant : public Bug {
public:
  Ant(int x, int y, int lifetime);
  virtual ~Ant();
};

class Queen : public Ant {
protected:
  int timeSinceMadeQueen;
  int timeSinceMated;

public:
  Queen(int x, int y, int lifetime);
  virtual ~Queen();

  // moves the bug, prioritizes positions where a bug exists
  virtual void move(Bug *db, vector<Bug *> &bugs,
                    vector<pair<int, int>> positions) override;
  virtual bool starve() const override;
  virtual vector<pair<int, int>> canMove(vector<Bug *> &bugs, int x,
                                         int y) const override;
  virtual bool canBreed() const override;
  virtual void breed(vector<Bug *> &bugs) override;

  // Queen specific behavior
  bool canMove() const;
  void setTSQM();
  void setSM();
  void incTSQM();
  void incSM();
  int gettsmq() const;
  int getsm() const;

  double distance(int x1, int y1, int x2, int y2);
};

class Worker : public Ant {

public:
  Worker(int x, int y, int it);
  virtual ~Worker();

  // moves the bug, prioritizes positions where a bug exists
  virtual void move(Bug *db, vector<Bug *> &bugs,
                    vector<pair<int, int>> positions) override;
  virtual bool starve() const override;
  virtual vector<pair<int, int>> canMove(vector<Bug *> &bugs, int x,
                                         int y) const override;
  virtual bool canBreed() const override;
  virtual void breed(vector<Bug *> &bugs) override;
};

class MaleAnt : public Worker {
public:
  MaleAnt(int x, int y, int it);
  virtual ~MaleAnt();
  virtual bool canBreed() const override;
  virtual void breed(vector<Bug *> &bugs) override;
};

#endif