#include "bug.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ncurses.h>
#include <random>
#include <utility>
#include <vector>

// Bug methods
Bug::Bug(int x, int y, int initializedTime)
    : x(x), y(y), it(initializedTime), symbol('?'), starveTicks(0) {}

// does a bug exist at this position?
bool Bug::bug_exists(vector<Bug *> &bugs, int x, int y) {
  for (Bug *bug : bugs) {
    if (bug->getX() == x && bug->getY() == y) {
      return true;
    }
  }
  return false;
}

// only call this when YOU  KNOW A BUG EXISTS AT THE COORD
char Bug::typeAtCoord(vector<Bug *> &bugs, int x, int y) {
  for (Bug *bug : bugs) {
    if (bug->getX() == x && bug->getY() == y) {
      return bug->getSymbol();
    }
  }
}

// draws the bug  on the board
void Bug::draw_Bug(Bug *bug) {
  mvprintw(bug->getY(), bug->getX(), "%c", bug->getSymbol());
}

// debugging into
void Bug::display_bug_info(int count, int x, int y, Bug *bug) {
  mvprintw(y, x, "[%i] Bug: x %i, y %i, it %i, s %c ST %i", count, bug->getX(),
           bug->getY(), bug->getInitalizedTime(), bug->getSymbol(),
           bug->getStarveTicks());
}

// deleted the bug at coord, ie it starved/ died/ was eaten
void Bug::remove_eaten_bug(vector<Bug *> &bugs, int x, int y) {
  for (auto it = bugs.begin(); it != bugs.end();) {
    if ((*it)->getX() == x && (*it)->getY() == y) {
      delete *it;
      it = bugs.erase(it);

    } else {
      ++it;
    }
  }
}

void Bug::incTime(Bug *bug) { bug->it++; }

void Bug::incStarve(Bug *bug) { bug->starveTicks++; }

// Compare the indexes of the order
bool Bug::compareBugs(const Bug *a, const Bug *b) {
  const string order = "XQow";
  auto orderA = order.find(a->getSymbol());
  auto orderB = order.find(b->getSymbol());

  return orderA < orderB;
}

void Bug::bounce(int newPx, int newPy, int oldPx, int oldPy, Bug *bug,
                 vector<Bug *> bugs) {
  int deltaX = newPx - oldPx;
  int deltaY = newPy - oldPy;

  // case 1 diag up left
  if (deltaY == -1 && deltaX == -1) {
    newPx++;
    newPy--;

    // case 2 diag up right
  } else if (deltaY == -1 && deltaX == 1) {
    newPx--;
    newPy--;
    // case 3 diag down left
  } else if (deltaY == 1 && deltaX == 1) {
    newPx--;
    newPy++;
    // case 4 diag down right
  } else if (deltaY == 1 && deltaX == -1) {
    newPx++;
    newPy++;
    // case 5: down left right up
  } else if (deltaY == 0 || deltaX == 0) {
    newPx = oldPx;
    newPy = oldPy;
  }
  if (Bug::bug_exists(bugs, newPx, newPy)) {
    Bug::remove_eaten_bug(bugs, newPx, newPy);
    bug->resetStarveTicks();
  }

  bug->setX(newPx);
  bug->setY(newPy);

  //-----------------------------------------------------------------

  // bring it back to same spot

  // case 6: into bottom left corner
  // case 7: into bottom right corner
  // case 8: into top left corner
  // case 9: into top right corner
  //---------------------------------------------------
}

// adds a bug to the vector of bugs,
void Bug::addBug(vector<Bug *> &bugs, Bug *newBug) {
  auto it = lower_bound(bugs.begin(), bugs.end(), newBug, compareBugs);
  bugs.insert(it, newBug);
}

char Bug::getSymbol() const { return symbol; }

int Bug::getX() const { return x; }

int Bug::getY() const { return y; }

int Bug::getInitalizedTime() const { return it; }

int Bug::getStarveTicks() const { return starveTicks; }

void Bug::setX(int x) { this->x = x; }

void Bug::setY(int y) { this->y = y; }

void Bug::resetStarveTicks() { (*this).starveTicks = 0; }

//-----------------------------------------------------------------------------------------

// DoodleBug methods
DoodleBug::DoodleBug(int x, int y, int it) : Bug(x, y, it) { symbol = 'X'; };
DoodleBug::~DoodleBug() {}

// assume the vector are valid positions to move to, positions are coordinates
// that are in range of bug, including
void DoodleBug::move(Bug *db, vector<Bug *> &bugs,
                     vector<pair<int, int>> positions) {
  // positions a bug exists out of valid coords
  vector<pair<int, int>> bugPositions;
  char sym;
  char charAtPos;

  // if its valid, add to new vector
  for (const auto &pos : positions) {
    if (Bug::bug_exists(bugs, pos.first, pos.second)) {
      sym = Bug::typeAtCoord(bugs, pos.first, pos.second);
      if (sym == 'Q' || sym == 'o' || sym == 'w') {
        bugPositions.push_back(pos);
      }
    }
  }

  // if there are bugs in the area, store bugs coords, delete it, move to that
  // coord
  if (!bugPositions.empty()) {
    int index = rand() % bugPositions.size();
    auto newPosition = bugPositions[index];
    Bug::remove_eaten_bug(bugs, newPosition.first, newPosition.second);
    db->setX(newPosition.first);
    db->setY(newPosition.second);
    db->resetStarveTicks();
  } else {
    Bug::incStarve(db);
    int index = rand() % positions.size();
    auto newPosition = positions[index];
    // get the char at position, border check
    charAtPos = mvinch(newPosition.second, newPosition.first) & A_CHARTEXT;
    // is it a border?
    if (charAtPos == '*') {
      Bug::bounce(newPosition.second, newPosition.first, db->getX(), db->getY(),
                  db, bugs);

    } else {
      db->setX(newPosition.first);
      db->setY(newPosition.second);
    }
  }
}

// true if dodlebug hasnt eaten in 10
bool DoodleBug::starve() const { return Bug::getStarveTicks() >= 20; }

// gets the coordinates a doodlebug can move to, valid if it doesnt contain a
// doodleBig
vector<pair<int, int>> DoodleBug::canMove(vector<Bug *> &bugs, int x,
                                          int y) const {
  vector<pair<int, int>> temp;
  for (int i = x - 1; i < x + 2; i++) {
    for (int j = y - 1; j < y + 2; j++) {
      char ch = mvinch(j, i);
      if (ch != '*' && ch != 'X') {
        temp.emplace_back(i, j);
      }
    }
  }
  return temp;
}

// true if the doodlebugs increment time is > 0 and a multiple of 10. false
// otherwise
bool DoodleBug::canBreed() const {
  return (Bug::getInitalizedTime() > 0 && Bug::getInitalizedTime() % 10 == 0);
}

// makes a new doodlebug, and calls add_bug with it
void DoodleBug::breed(vector<Bug *> &bugs) {
  // 8-adjacent for now,
  vector<pair<int, int>> temp;
  for (int i = x - 1; i < x + 2; i++) {
    for (int j = y - 1; j < y + 2; j++) {
      char ch = mvinch(j, i);
      if (ch != '*' && ch != 'X' && ch != 'w' && ch != 'Q' && ch != 'o') {
        temp.emplace_back(i, j);
      }
    }
  }
  if (temp.empty()) {
    // do nothinng
  } else {
    int index = rand() % temp.size();
    auto newPosition = temp[index];
    Bug::addBug(bugs, new DoodleBug(newPosition.first, newPosition.second, 0));
  }
}

//-------------------------------------------------------------------------------------------------------
// Ant methods
Ant::Ant(int x, int y, int lifetime) : Bug(x, y, lifetime) { symbol = 'a'; };
Ant::~Ant() {}

//-------------------------------------------------------------------------------------------------------
// Queen methods
Queen::Queen(int x, int y, int lifetime) : Ant(x, y, lifetime) {
  symbol = 'Q';
  timeSinceMadeQueen = 0;
  timeSinceMated = 0;
};
Queen::~Queen() {}

// moves the queen to a valid square if canMove(vector<...<) returns a vector of
// coords > 0. That method calls canMove() which establishes if the queen is in
// a state where it can move, ie its been more than 25 seconds since it was
// initalized
void Queen::move(Bug *queen, vector<Bug *> &bugs,
                 vector<pair<int, int>> positions) {

  char sym;
  char charAtPos;

  int index = rand() % positions.size();
  auto newPosition = positions[index];
  // get the char at position, border check
  charAtPos = mvinch(newPosition.second, newPosition.first) & A_CHARTEXT;
  // is it a border?
  if (charAtPos == '*') {
    Bug::bounce(newPosition.second, newPosition.first, queen->getX(),
                queen->getY(), queen, bugs);

  } else {
    queen->setX(newPosition.first);
    queen->setY(newPosition.second);
  }
}

int Queen::gettsmq() const { return timeSinceMadeQueen; };
int Queen::getsm() const { return timeSinceMated; };

void Queen::setTSQM() { (*this).timeSinceMadeQueen = 0; }
void Queen::setSM() { (*this).timeSinceMated = 0; }

void Queen::incTSQM() { (*this).timeSinceMadeQueen++; }
void Queen::incSM() { (*this).timeSinceMated++; }

// if starveTicks is >= 60, true
bool Queen::starve() const { return (Bug::getStarveTicks() >= 60); }

vector<pair<int, int>> Queen::canMove(vector<Bug *> &bugs, int x, int y) const {
  vector<pair<int, int>> temp;
  if (Queen::canMove()) {
    for (int i = x - 1; i < x + 2; i++) {
      for (int j = y - 1; j < y + 2; j++) {
        char ch = mvinch(j, i);
        if (ch != '*' && ch != 'X' && ch != 'w' && ch != 'o' && ch != 'Q') {
          temp.emplace_back(i, j);
        }
      }
    }
  }
  return temp;
}

// has it been 25 seconds since the queen was initalized
bool Queen::canMove() const {
  return (Bug::getInitalizedTime() >= 25) && Queen::getsm() > 10;
}

bool Queen::canBreed() const {
  bool flag = false;
  for (int i = -1; i < x + 2; i++) {
    for (int j = y - 1; j < y + 2; j++) {
      char ch = mvinch(j, i);
      if (ch == 'o') {
        flag = true;
      }
    }
  }
  return Bug::getStarveTicks() > 25 && flag;
}

double Queen::distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void Queen::breed(vector<Bug *> &bugs) {
  int max = 10;
  vector<pair<int, int>> possibleQueenSpots;

  if (Queen::canBreed()) {
    for (int i = x - 2; i < x + 3; i++) {
      for (int j = y - 2; j < y + 3; j++) {
        char ch = mvinch(j, i);
        if (ch != '*' && ch != 'X' && ch != 'w' && ch != 'o' && ch != 'Q') {
          possibleQueenSpots.emplace_back(i, j);
          int mOrF = rand() % 2;
          if (max > 0) {
            if (mOrF == 0) {
              Bug::addBug(bugs, new Worker(i, j, 0));
            } else {
              Bug::addBug(bugs, new MaleAnt(i, j, 0));
            }
            max--;
          }
        }
      }
    }
    Queen::setTSQM();
    sort(possibleQueenSpots.begin(), possibleQueenSpots.end(),
         [&](pair<int, int> p1, pair<int, int> p2) {
           return Queen::distance(p1.first, p1.second, x, y) <
                  Queen::distance(p2.first, p2.second, x, y);
         });
    Bug::addBug(bugs, new Queen(possibleQueenSpots.at(0).first,
                                possibleQueenSpots.at(0).second, 0));
    Bug::resetStarveTicks();

    Queen::setSM();
  }
}

//---------------------------------------------------------------------------------------------------------------
// Worker methods
Worker::Worker(int x, int y, int it) : Ant(x, y, it) { symbol = 'w'; };

Worker::~Worker() {}

void Worker::move(Bug *worker, vector<Bug *> &bugs,
                  vector<pair<int, int>> positions) {

  char sym;
  char charAtPos;

  int index = rand() % positions.size();
  auto newPosition = positions[index];
  // get the char at position, border check
  charAtPos = mvinch(newPosition.second, newPosition.first) & A_CHARTEXT;
  // is it a border?
  if (charAtPos == '*') {
    Bug::bounce(newPosition.second, newPosition.first, worker->getX(),
                worker->getY(), worker, bugs);

  } else {
    worker->setX(newPosition.first);
    worker->setY(newPosition.second);
  }
}

bool Worker::starve() const { return (Bug::getStarveTicks() > 5); }

vector<pair<int, int>> Worker::canMove(vector<Bug *> &bugs, int x,
                                       int y) const {
  vector<pair<int, int>> temp;
  for (int i = x - 1; i < x + 2; i++) {
    for (int j = y - 1; j < y + 2; j++) {
      char ch = mvinch(j, i);
      if (ch != '*' && ch != 'X' && ch != 'w' && ch != 'o' && ch != 'Q') {
        temp.emplace_back(i, j);
      }
    }
  }
  return temp;
}

bool Worker::canBreed() const {
  // TODO
  return false;
}

void Worker::breed(vector<Bug *> &bugs) {
  // TODO
}

// MaleAnt methods
MaleAnt::MaleAnt(int x, int y, int it) : Worker(x, y, it) { symbol = 'o'; };

bool MaleAnt::canBreed() const {
  // TODO
  return false;
}

void MaleAnt::breed(vector<Bug *> &bugs) {
  // TODO
}

MaleAnt::~MaleAnt() {}