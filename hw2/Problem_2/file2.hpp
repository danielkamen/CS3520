#include <iostream>
#include <vector>
#include <String>

using namespace std;

 class ScamWord {
    public:
    string word;
    int value;
    // A flag, if its 0 and scanFileScammer() finds this word, return the line. if > 0, dont return the line.
    int firstLineFoundOn = 0;
    // how many times has this word been found?
    int timesFound = 0;
    // indivual word point total:
    int wordPointTotal = 0;

    string lineFirstFoundOn = "Word wasn't found in file";
 };


namespace std1 {

// scans the line if it contains any of the scam words in the list of flagged words. Retu
void scanFileScammer(string token, vector<ScamWord> words, string line);

// collects the total sum of all the sus words in the file
int sumOfSusWords(vector<ScamWord> words);

// For  each  keyword  or  phrase  found,  output one line with the word or phrase, the number of occurrences and the point total. 
string outputOfText(vector<ScamWord> words);
}