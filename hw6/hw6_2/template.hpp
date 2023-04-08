#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

template <class T> class Repository {
private:
  map<int, T> data;
  int size;

public:
  void printList() {
    cout << "Size: " << getSize() << endl;
    for (const auto &dat : data) {
      cout << "Key/ Postition: " << dat.first << ", Value: " << dat.second
           << endl;
    }
    cout << endl;
  }

  int getSize() { return data.size(); }

  ~Repository(){};
  // rule of 5 (# 1)
  Repository(vector<T> newData) {
    int i = 0;
    cout << "Construtor" << endl;
    for (const auto &dat : newData) {
      data.insert(make_pair(i, dat));
      i++;
    }
    size = data.size();
    printList();
  }

  // rule of 5 (# 2) copy constructor
  Repository(const Repository &other) : data(other.data), size(other.size) {
    cout << "Copy Construtor" << endl;
  }

  // rule of 5 (# 3) move
  Repository(Repository &&other) : data(move(other.data)), size(other.size) {
    cout << "Move Construtor" << endl;
  }

  // rule of 5 (# 4) copy assignment operator
  Repository &operator=(const Repository &other) {
    if (this != &other) {
      data = other.data;
      size = other.size;
    }
    cout << "Copy assignment Construtor" << endl;
    return *this;
  }

  // rule of 5 (# 5) move assingment op
  Repository &operator=(Repository &&other) {
    if (this != &other) {
      data = move(other.data);
      size = other.size;
    }
    cout << "Move Assignment Construtor" << endl;
    return *this;
  }

  void add(T item) {
    int pos = contains(item);
    if (pos > -1) {
      cout << "item already existed, setting its data to new item: " << item
           << endl;
      data.at(pos) = item;
    } else {
      data.insert(make_pair(Repository::getSize(), item));
      cout << "Added:" << item << endl;
    }
  }

  void add(vector<T> items) {
    for (const auto &item : items) {
      Repository<T>::add(item);
    }
    printList();
    cout << endl;
  }

  void remove(T item) {
    for (auto iter = data.begin(); iter != data.end(); ++iter) {
      if (iter->second == item) {
        data.erase(iter);
        cout << "removed"
             << " " << item << endl;
        return;
      }
    }
  }

  void remove(vector<T> items) {
    for (const auto &item : items) {
      Repository<T>::remove(item);
    }
    printList();
    cout << endl;
  }

  int contains(T item) {
    bool flag = false;
    int itsID;
    for (const auto &pair : data) {
      if (pair.second == item) {
        flag = true;
        itsID = pair.first;
        break;
      }
    }
    if (flag) {
      // also its position
      cout << item << " was found at: " << itsID << " (0th-indexing)" << endl;
      return itsID;

    } else {
      cout << item << " wasnt found." << endl;
      return -1;
    }
  }
};
