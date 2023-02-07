#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ScamWord {
public:
    string word;
    int value;

    // how many times has this word been found?
    int timesFound;
    // indivual word point total:
    int wordPointTotal;

    string lineFirstFoundOn;
};


namespace std1 {

    // collects the total sum of all the sus words in the file
    int sumOfSusWordPoints(vector<ScamWord> words);

    // collects the total number of sus words found in file
    int sumOfSusWords(vector<ScamWord> words);
}