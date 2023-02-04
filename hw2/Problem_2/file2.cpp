#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "file2.hpp"
using namespace std;

namespace std1 {

// scans the line if it contains any of the scam words in the list of flagged words. Retu
void scanFileScammer(string token, vector<ScamWord> words, string line) {
     
      for(int i = 0; i < words.size(); i++) {
        // if the sus word was found
        if (token == words[i].word) {
            // adds the line to be returned with the word
            if (words[i].firstLineFoundOn == 0) {
                words[i].lineFirstFoundOn = line;
            }
            words[i].timesFound++;
            words[i].wordPointTotal = words[i].value * words[i].timesFound;
        }
      }
    }



int sumOfSusWords(vector<ScamWord> words) {
    int sum = 0;
    for(int i = 0; i< words.size(); i++){
        sum =  sum + words[i].wordPointTotal;
    }
    return sum;
}

string outputOfText(vector<ScamWord> words) {
    for(int i = 0; i < words.size(); i++){
        cout<<"Sus Word:        "<< words[i].word<<"             was found on this line: "<<endl;
        cout<<words[i].lineFirstFoundOn<<endl;
        cout<<"It was found: "<<words[i].timesFound<<" times"<<endl;
        cout<<"Its individual word score was: "<<words[i].wordPointTotal<<endl;
    }
}


}