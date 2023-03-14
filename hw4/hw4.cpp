#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <forward_list>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class WordInfo {
private:
  string word;
  int count;

public:
  // constructor: count is always one at this point
  WordInfo(string w) : word(w), count(1) {}

  string get_word() const { return (*this).word; }
  void increase_count() { (*this).count++; }

  int get_count() const { return (*this).count; }

  // displays information about the class
  void output() const {
    cout << word << " {Word Length: " << word.length()
         << "} :" << (*this).get_count() << endl;
  }
  bool operator==(const WordInfo &other) const {
    return this->word == other.word;
  }
};

typedef class WordInfo WordInfo;

int main(void) {
  // contains all unique words
  set<string> uniqueWordsFromFile;
  // contains all words starting with vowel

  auto cmp = [](WordInfo a, WordInfo b) {
    return a.get_count() < b.get_count();
  };
  set<WordInfo, decltype(cmp)> listOfVowelWords(cmp);
  // contains list of every word from file
  vector<string> allWordsFromFile;

  // variables that are displayed + calculated for each file
  int numOfWords;
  int numOfWordsStartingWithVowel;
  int distinctWordsLEQGivenLength;

  // variables for the containers
  // container storing word + # of occurances

  // container for every word in the input file stored seperatly

  /*
  // input and output work, and allows the user to pick which file they would
  // like to test hope this is ok TA :)
  string input;
  cout << "Hello, get the stats of a file" << endl;
  cout << "Your choices are: large.txt and small.txt" << endl;
  cin >> input;

  while (input != "small.txt" && input != "large.txt") {
    cout << "Please try again" << endl;
    cin >> input;
  }
  */

  const string outfilePath = "statistics.txt";
  const string infilePath = "small.txt";

  // Connect output stream to file
  ofstream out(outfilePath.c_str());
  // Redirect cout to output.txt
  cout.rdbuf(out.rdbuf());

  // Connect input stream to file
  ifstream in(infilePath.c_str());
  // Check for validity, return an error if invalid
  if (!in) {
    cout << "Error" << endl;
    return EXIT_FAILURE;
  }
  // line.beginLine.end
  //  Read input stream into stringstream buffer
  stringstream buffers;
  buffers << in.rdbuf();
  string line;

  // loops through each line
  while (getline(buffers, line)) {
    stringstream lineStream(line);
    string token;
    // loops through each word/token
    while (lineStream >> token) {
      char letter = (token[0]);
      switch (letter) {
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U':
        { auto post = find(listOfVowelWords.begin(), listOfVowelWords.end(),
                         WordInfo(token));
        if (post != listOfVowelWords.end()) {
          WordInfo *temp = new WordInfo(*post);
          temp->increase_count();
          listOfVowelWords.erase(post);
          listOfVowelWords.insert(*temp);
        } else {
          WordInfo *temp = new WordInfo(token);
          listOfVowelWords.insert(*temp);
        }
        break;
          }
      default:
        break;
      }

      numOfWords++;
    }
  }

  cout << "Number of words in file that are lower case: "
       << listOfVowelWords.size() << endl;
  for (auto w : listOfVowelWords) {
    w.output();
  }
}
