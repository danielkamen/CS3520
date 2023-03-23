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
    cout << word << "     Word Length: " << word.length()
         << ", Frequency : " << (*this).get_count() << endl;
  }
  // overloads == to only compare words
  bool operator(const WordInfo &other) const {
    return this->word == other.word;
  }

};



typedef class WordInfo WordInfo;

int main(void) {
  // contains all unique words
  set<string> uniqueWordsFromFile;


  // contains all words starting with vowel
  auto cmp = [](WordInfo a, WordInfo b) {
  return a.get_word() < b.get_word();
};
  set<WordInfo, decltype(cmp)> listOfVowelWords(cmp);
  // contains list of every word from file
  vector<string> allWordsFromFile;


  // variables for the containers
  // container storing word + # of occurances

  // container for every word in the input file stored seperatly

  
  // input and output work, and allows the user to pick which file they would
  // like to test hope this is ok TA :)
  string input;
  int actLength;
  cout << "Hello, get the stats of a file" << endl;
  cout << "Your choices are: large.txt and small.txt" << endl;
  cin >> input;

  while (input != "small.txt" && input != "large.txt") {
    cout << "Please try again" << endl;
    cin.clear();
    cin >> input;
  }
  cin.clear();
  cout<<endl;
  cout<<"Please enter a number. This represents the length of a word, and you will be returned the number of words less than or equal to that length"<<endl;
  cout<<"remeber, a word length must be greater than 0!"<<endl;
  cout<<"Enter the number:";
  
  
// input validation
    while (!(cin>>actLength)) {
      cout<<"Try again"<<endl;
      cin.clear();
      cin.ignore(123,'\n');
    }
  cout<<endl;

  string TypeOfInputs;
  cout << "Your choices are: consonants [c] or vowels [v]. Press which ever button youd like to gets stats for" << endl;
  cin >> TypeOfInputs;
  while (TypeOfInputs != "c" && TypeOfInputs != "v") {
    cout << "Please try again" << endl;
    cin.clear();
    cin >> TypeOfInputs;
  }
  

  cout<<"Please go to statistics.txt to see your custom data!"<<endl;

  const string outfilePath = "statistics.txt";
  const string infilePath = input;

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
      // UNIQUE WORDDS ARE CASE SENSITIVE!!!!!
       uniqueWordsFromFile.insert(token);
      for (int j = 0; j < token.length(); ++j) {
                    token[j] = tolower(token[j]);

                    // remove special cases
                }
      allWordsFromFile.push_back(token);
     
    }
  }

  


// gets every word from file, and if its a vowel (already been converted to lower case) its checked to see if its already in the set of collected vowels. If not, it is added to the set. If it is already present, a new wordinfo is created with an incremented count and put into the set, old one is deleted.
if (TypeOfInputs == "v") {
  for (auto w : allWordsFromFile) {
      char letter = (w[0]);
      switch (letter) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u': {
        auto post = find(listOfVowelWords.begin(), listOfVowelWords.end(),
                         WordInfo(w));
        if (post != listOfVowelWords.end()) {
          WordInfo *temp = new WordInfo(*post);
          temp->increase_count();
          listOfVowelWords.erase(post);
          listOfVowelWords.insert(*temp);
        } else {
          WordInfo *temp = new WordInfo(w);
          listOfVowelWords.insert(*temp);
        }
      }; break;
      }


  }
} else {
  for (auto w : allWordsFromFile) {
      char letter = (w[0]);
      switch (letter) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u': 
      break;
      default:
      {
        auto post = find(listOfVowelWords.begin(), listOfVowelWords.end(),
                         WordInfo(w));
        if (post != listOfVowelWords.end()) {
          WordInfo *temp = new WordInfo(*post);
          temp->increase_count();
          listOfVowelWords.erase(post);
          listOfVowelWords.insert(*temp);
        } else {
          WordInfo *temp = new WordInfo(w);
          listOfVowelWords.insert(*temp);
        }
      }; break;
      }


  }
}

cout<<"Number of words in "<<input<<" : "<<allWordsFromFile.size()<<endl; 
  int counttemp = 0;
  for (auto w : listOfVowelWords) {

    counttemp = counttemp + w.get_count();
  }
  string typeOfInput;
  if (TypeOfInputs == "c") {
    typeOfInput = "consanants";
  } else {
     typeOfInput = "vowels";
  }
  cout << "Number of words in "<<input<<" : "<<"starting with " << typeOfInput << " "
       << counttemp << endl;

    vector<WordInfo> listofSortedVowelsByCount;  

    // places the unique WordInfo into a vector which can be sorted based on the counts (cant resort a set)
  for (auto w : listOfVowelWords) {
    listofSortedVowelsByCount.push_back(w);
  }

  // sorts from highest to lowest count
  sort(listofSortedVowelsByCount.begin(), listofSortedVowelsByCount.end(), [](const WordInfo& left, const WordInfo& right) {
    return left.get_count() > right.get_count();
  }
  
  );

  // outputs the data of each WordInfo
for (auto w : listofSortedVowelsByCount) {
    w.output();
  }

int countOfWordsLEQToGivenLength = 0;

  // now to handle how many unique words there are with length <= actLength
  for (auto w: uniqueWordsFromFile) {
    if (w.length() <= actLength) {
      countOfWordsLEQToGivenLength++;
    }
  }

   cout<<"There are "<<countOfWordsLEQToGivenLength<<" of words in "<<input<<" with a length LEQ "<<actLength<<". "<<endl;

}
