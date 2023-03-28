#include <ncurses.h>
#include <cstdlib>
#include "bug.hpp"

// Bug methods
Bug::Bug(int x, int y, int initializedTime)
    : x(x), y(y), it(initializedTime), symbol('?') {}

bool Bug::bug_exists(vector<Bug*>& bugs, int x, int y) {
     for (Bug& bug : bugs) {
        if (bug->getX() == x && bug->getY() == y) {
            return true;
        }
    }
    return false;
}


  // draws the bug  on the board
void Bug::draw_Bug(Bug* bug) 
 
{
    mvprintw(bug->getY(), bug->getX(), "%c", bug->getSymbol());
}

void Bug::remove_eaten_bug(vector<Bug*>& bugs, int x, int y) {
 for (auto it = bugs.begin(); it != bugs.end(); ) {
        if ((*it)->getX() == x && (*it)->getY() == y) {
            delete *it;
             it = bugs.erase(it);
        } else {
            ++it;
        }
    }
}

// used to sort
//bool Bug::operator==(const Bug& other) {
//
//}

// Compare the indexes of the order 
bool Bug::compareBugs(const Bug* a, const  Bug* b) {
  const string order = "XQow";
  auto orderA = order.find(a->getSymbol());
  auto orderB = order.find(b->getSymbol());
  
  return orderA < orderB;
}


void Bug::addBug(vector<Bug*>& bugs, Bug* newBug) {
  auto it = lower_bound(bugs.begin(), bugs.end(), newBug, compareBugs);
  bugs.insert(it, newBug);
}

char Bug::getSymbol() const {
    return symbol;
}


int Bug::getX() const {
    return x;
}

int Bug::getY() const {
    return y;
}

int Bug::getInitalizedTime() const {
    return it;
}

void Bug::setX(int x) {
    this->x = x;
}

void Bug::setY(int y) {
    this->y = y;
}

// DoodleBug methods
DoodleBug:: DoodleBug(int x, int y, int it) : Bug(x, y, it) {
    symbol = 'X';
    timeSinceEating = 0;
  };
DoodleBug::~DoodleBug() {}



void DoodleBug::move() {
    
}

bool DoodleBug::starve() const {
    // TODO
    return false;
}

bool DoodleBug::canMove(vector<Bug*>& bugs, int x, int y) const {
    // TODO
    return false;
}

bool DoodleBug::canBreed() const override {
     return (it > 0 && it % 10 == 0);
}

void DoodleBug::breed(vector<Bug*>& bugs) const override {
    // TODO
}


// Ant methods
Ant:: Ant(int x, int y, int lifetime) : Bug(x, y, lifetime) {
    symbol = 'a';
};
Ant::~Ant() {}

// Queen methods
Queen::Queen(int x, int y, int lifetime) : Ant(x, y, lifetime) {
    symbol = 'Q';
    timeSinceMadeQueen = 0;
    timeSinceLayedEggs = 0;
    timeSinceMated = 0;
  };
Queen::~Queen() {}

void Queen::move() {
    // TODO
}

bool Queen::starve() const {
    // TODO
    return false;
}

bool Queen::canMove(vector<Bug*>& bugs, int x, int y) const {
    // TODO
    return false;
}

bool Queen::canMate() const {
    // TODO
    return false;
}

bool Queen::canMove() const {
    // TODO
    return false;
}

bool Queen::canBreed() const override {
    // TODO
    return false;
}

void Queen::breed(vector<Bug*>& bugs) const override {
    // TODO
}

// Worker methods
Worker::Worker(int x, int y, int it) : Ant(x, y, it) {
    symbol = 'w';
    timeSinceMoved = 0;
  };

Worker::~Worker() {}

void Worker::move() {
    // TODO
}

bool Worker::starve() const {
    // TODO
    return false;
}

bool Worker::canMove(vector<Bug*>& bugs, int x, int y) const {
    // TODO
    return false;
}


bool Worker::canBreed() const override {
    // TODO
    return false;
}

void Worker::breed(vector<Bug*>& bugs) const override {
    // TODO
}


// MaleAnt methods
MaleAnt::MaleAnt(int x, int y, int it) : Worker(x, y, it) { symbol = 'o'; };

bool MaleAnt::canBreed() const override {
    // TODO
    return false;
}

void MaleAnt::breed(vector<Bug*>& bugs) const override {
    // TODO
}


MaleAnt::~MaleAnt() {}