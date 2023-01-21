#include <iostream>
#include<string>
#include <vector>
#include<cstdlib>

using namespace std;

int main(){

    //delcares variable
    string paragraph;
    int words = 0, consonants = 0, vowels = 0, includeSpecial = 0, startWithVowel = 0;

    cout<<"Please enter a paragraph. Press [Enter] when you are done."<<endl;
    getline(cin, paragraph);
    if (paragraph.empty()) { 
        cout << "Error! Paragraph name is required.\n";
}
    int lenParagraph = paragraph.size();
    cout<<"What you typed:"<<paragraph<<endl;
    for(int i = 0; i<= lenParagraph; i++){
        if(paragraph[i] == ' '){
            words++;
        }
    }
    words++;
    cout<<"Number of words typed: "<<words<<endl;

    // makes a vector of the position of the spaces
    // goal: use this to check substring between spaces if they contain:
     //  ! . , ; “ ‘ ? $ 
    vector<int> posOfSpace(0);
    posOfSpace.push_back(0);
    for(int i = 0; i<= lenParagraph; i++){
        if(paragraph[i] == ' '){
            posOfSpace.push_back(i);
        }
    }
    posOfSpace.push_back(lenParagraph);
   
    for(int i = 0; i<posOfSpace.size() - 1; i++){
        string tempWord = paragraph.substr(posOfSpace.at(i), (posOfSpace.at(i+1)- posOfSpace.at(i)));
         char apos = char(39);
         bool found1 = tempWord.find('!') > 0 && tempWord.find('!') <= tempWord.size();
         bool found2 = tempWord.find('.') > 0 && tempWord.find('.') <= tempWord.size();
         bool found3 = tempWord.find(',') > 0 && tempWord.find(',') <= tempWord.size();
         bool found4 = tempWord.find(';') > 0 && tempWord.find(';') <= tempWord.size();
         bool found5 = tempWord.find(apos) > 0 && tempWord.find(apos) <= tempWord.size();
         bool found6 = tempWord.find('?') > 0 && tempWord.find('?') <= tempWord.size();
        if(found1 || found2 || found3 || found4 || found5 || found6){
        includeSpecial++;
        }
    }
    cout<<"Number of words that contain a special character: "<<includeSpecial<<endl;

    for(int i = 0; i<posOfSpace.size() - 1; i++){
        string tempWord = paragraph.substr(posOfSpace.at(i), (posOfSpace.at(i+1)- posOfSpace.at(i)));
        if( toupper(tempWord.at(0)) == 'A' || toupper(tempWord.at(0)) == 'E' || toupper(tempWord.at(0)) == 'I' || toupper(tempWord.at(0)) == 'O' || toupper(tempWord.at(0)) == 'U'){
            startWithVowel++;
        }
    }

    for(int i = 0; i <lenParagraph; i++){
        char letter = paragraph[i];
        switch(tolower(letter))
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
            case 'j':consonants++; break;
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
    cout<<"Number of vowels: "<<vowels<<endl;
    cout<<"Number of consonants: "<<consonants<<endl;

    int lengthUser;
    cout<<"Please type a number, and I will return all words you typed that are longer than that number: ";
    cin>>lengthUser;

    for(int i = 0; i<posOfSpace.size() - 1; i++){
        string tempWord = paragraph.substr(posOfSpace.at(i), (posOfSpace.at(i+1)-posOfSpace.at(i)));
        if(tempWord.size() > lengthUser + 1){
            cout<<tempWord<< endl;
        }
    }
    srand((unsigned) time(NULL));
    int randomNum = 6 + rand() % 5;
    cout<<"Generating a random number from 6-10 which will download a virus onto your computer: "<< randomNum<<endl;
    for(int i = 0; i<posOfSpace.size() - 1; i++){
        string tempWord = paragraph.substr(posOfSpace.at(i), (posOfSpace.at(i+1)-posOfSpace.at(i)));
        if(tempWord.size() < randomNum){
            cout<<tempWord<< endl;
        }
    }
}
