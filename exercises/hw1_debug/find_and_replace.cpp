#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    //delcares variable
    string paragraph;
    string goalWord;
    string newWord;
    int count = 0;
    int position = 0;
    vector<int> posOfWords(0);
    vector<int> wordsVec(0);
    vector<int> posOfSpace(0);
    posOfSpace.push_back(0);

    // section dealing with user input
    cout << "Please enter a paragraph. Press [Enter] when you are done." << endl;
    getline(cin, paragraph);
    if (paragraph.empty()) {
        cout << "Error! Paragraph name is required.\n";
    }
    int lenParagraph = paragraph.size();

    // section dealing with user input for finding a word
    cout << "Please type a word you want to find: ";
    cin >> goalWord;
    if (goalWord.size() < 2) {
        cout << "Error! Longer word is required.\n";\
    }
    int wordLength = goalWord.size();

    
    // makes a vector of position of spaces
    for (int i = 0; i <= lenParagraph; i++) {
        if (paragraph[i] == ' ') {
            posOfSpace.push_back(i);
        }
    }
    posOfSpace.push_back(lenParagraph);

    // makes a vector of the words
        for (int i = 0; i < posOfSpace.size() - 1; i++) {
            if (i == 0) {
                wordsVec.push_back(paragraph.substr(0, (posOfSpace.at(i + 1))));
                
            }
            else {
            wordsVec.push_back(paragraph.substr(posOfSpace.at(i) + 1, (posOfSpace.at(i + 1) - posOfSpace.at(i) - 1)));
            }
        }

    for (int i = 0; i < wordsVec.size(); i++) {
            if (wordsVec[i] == goalWord) {
                count++;
                cout << "Position of the word: " << posOfSpace.at(i) + 1 << endl;
        }
    }
    cout << "Total number of times the word was found: " << count << endl;

    cout << "Please type another word to replace the word you sought to find: ";
    cin >> newWord;

    int lengthOfNewWord = newWord.size();
    int difInSizes = lengthOfNewWord - wordLength;
    for (int i = 0; i < posOfWords.size(); i++) {
        paragraph.erase(posOfWords.at(i), wordLength);
        paragraph.insert(posOfWords.at(i), newWord);
        for (int j = 1; j < posOfWords.size(); j++) {
            posOfWords[j] = posOfWords.at(j) + difInSizes;
        }
    }
    cout << "Here is the new paragraph\n";
    cout << paragraph << endl;

    return 0;




}