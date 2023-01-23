#include <iostream>
#include<string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {

    //delcares variable
    string paragraph;
    int words = 0, consonants = 0, vowels = 0, includeSpecial = 0, startWithVowel = 0;

    // paragraph input data
    cout << "Please enter a paragraph. Press [Enter] when you are done." << endl;
    getline(cin, paragraph);
    if (paragraph.empty()) {
        cout << "Error! Paragraph name is required.\n";
    }

    // determines how many words are there.
    int lenParagraph = paragraph.size();
    cout << "What you typed: " << paragraph << endl;
    for (int i = 0; i <= lenParagraph; i++) {
        if (paragraph[i] == ' ') {
            words++;
        }
    }
    // adds count for last word
    words++;
    cout << "Number of words typed: " << words << endl;

    // makes a vector of the position of the spaces
    // goal: use this to check substring between spaces if they contain:
     //  ! . , ; “ ‘ ? $ 
    vector<int> posOfSpace;
    posOfSpace.push_back(0);
    for (int i = 1; i <= lenParagraph; i++) {
        if (paragraph[i] == ' ') {
            posOfSpace.push_back(i);
        }
    }
    // adds an index at the end indicating a space after the last word (placeholder used to get the last word)
    posOfSpace.push_back(lenParagraph);

    // makes a vector of the words
    // gets a substring between the spaces(recored in vector posOfSpaces)
    vector<string> wordsVec;
        for (int i = 0; i < posOfSpace.size() - 1; i++) {
            if (i == 0) {
                wordsVec.push_back(paragraph.substr(0, (posOfSpace.at(i + 1))));
            }
            else {
            wordsVec.push_back(paragraph.substr(posOfSpace.at(i) + 1, (posOfSpace.at(i + 1) - posOfSpace.at(i))));
            }
        }

    // does each substring have a special character?
    for (int i = 0; i < wordsVec.size(); i++) {
        char apos = char(39);
        bool found1 = wordsVec[i].find('!') > 0 && wordsVec[i].find('!') <= wordsVec[i].size();
        bool found2 = wordsVec[i].find('.') > 0 && wordsVec[i].find('.') <= wordsVec[i].size();
        bool found3 = wordsVec[i].find(',') > 0 && wordsVec[i].find(',') <= wordsVec[i].size();
        bool found4 = wordsVec[i].find(';') > 0 && wordsVec[i].find(';') <= wordsVec[i].size();
        bool found5 = wordsVec[i].find(apos) > 0 && wordsVec[i].find(apos) <= wordsVec[i].size();
        bool found6 = wordsVec[i].find('?') > 0 && wordsVec[i].find('?') <= wordsVec[i].size();
        if (found1 || found2 || found3 || found4 || found5 || found6) {
            includeSpecial++;
        }
    }
    cout << "Number of words that contain a special character: " << includeSpecial << endl;

    for (int i = 0; i < wordsVec.size() - 1; i++) {
        if (toupper(wordsVec[i].at(0)) == 'A' || toupper(wordsVec[i].at(0)) == 'E' || toupper(wordsVec[i].at(0)) == 'I' || toupper(wordsVec[i].at(0)) == 'O' || toupper(wordsVec[i].at(0)) == 'U') {
            startWithVowel++;
        }
    }

    cout << "Number of words that start with a vowel: " << startWithVowel << endl;

    for (int i = 0; i < lenParagraph; i++) {
        char letter = paragraph[i];
        switch (tolower(letter))
        {
        case 'a': vowels++; break;
        case 'e': vowels++; break;
        case 'i': vowels++; break;
        case 'o': vowels++; break;
        case 'u': vowels++; break;
        case 'q': consonants++; break;
        case 'w': consonants++; break;
        case 'r': consonants++; break;
        case 't': consonants++; break;
        case 'y': consonants++; break;
        case 'p': consonants++; break;
        case 's': consonants++; break;
        case 'd': consonants++; break;
        case 'f': consonants++; break;
        case 'g': consonants++; break;
        case 'h': consonants++; break;
        case 'j': consonants++; break;
        case 'k': consonants++; break;
        case 'l': consonants++; break;
        case 'z': consonants++; break;
        case 'x': consonants++; break;
        case 'c': consonants++; break;
        case 'v': consonants++; break;
        case 'b': consonants++; break;
        case 'n': consonants++; break;
        case 'm': consonants++; break;
        }
    }
    cout << "Number of vowels: " << vowels << endl;
    cout << "Number of consonants: " << consonants << endl;

    int lengthUser;
    cout << "Please type a number, and I will return all words you typed that are longer than that number: ";
    cin >> lengthUser;

    for (int i = 0; i < wordsVec.size(); i++) {

        if (i == 0) {
            if (wordsVec[i].size() > lengthUser + 1) {
                cout << wordsVec[i] << endl;
            }
        }
        else {
            if (wordsVec[i].size() > lengthUser + 1) {
                cout << wordsVec[i] << endl;
            }
        }
    }

    srand((unsigned)time(NULL));
    int randomNum = 8;
    cout << "Generating a random number from 6-10, and return any word less than: " << randomNum << endl;
    for (int i = 0; i < wordsVec.size(); i++) {
        if (i == 0) {
            if (wordsVec[i].size() < lengthUser) {
                cout << wordsVec[i] << endl;
            }
        }
        else {
            if (wordsVec[i].size() < lengthUser) {
                cout << wordsVec[i] << endl;
            }
        }
    }
    return 0;
}
