#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    //delcares variable
    string paragraph;
    string goalWord;
    string newWord;
    int count = 0;
    int position = 0;
    vector<int> posOfWords(0);
    

    cout<<"Please enter a paragraph. Press [Enter] when you are done."<<endl;
    getline(cin, paragraph);
    if (paragraph.empty()) { 
        cout << "Error! Paragraph name is required.\n";
    }
    int lenParagraph = paragraph.size();

    cout<<"Please type a word you want to find: ";
    cin>>goalWord;
    if (goalWord.size() < 2) { 
        cout << "Error! Longer word is required.\n";\
    }
    int wordLength = goalWord.size();
   
    vector<int> posOfSpace(0);
    posOfSpace.push_back(0);
    for(int i = 0; i<= lenParagraph; i++){
        if(paragraph[i] == ' '){
            posOfSpace.push_back(i);
        }
    }
    posOfSpace.push_back(lenParagraph);
    

    for(int i = 0; i<posOfSpace.size() - 1; i++){
        if(i == 0) {
            string tempWord = paragraph.substr(0, (posOfSpace.at(1)));
            if(tempWord == goalWord){
         count++;
         cout<<"Position of the word: "<< 0 <<endl;
         posOfWords.push_back(posOfSpace.at(i));
        }
        }
        else {
        string tempWord = paragraph.substr(posOfSpace.at(i) + 1, (posOfSpace.at(i+1)- (posOfSpace.at(i) + 1)));
        if(tempWord == goalWord){
         count++;
         cout<<"Position of the word: "<< posOfSpace.at(i) + 1 <<endl;
        posOfWords.push_back(posOfSpace.at(i) + 1 );
        }
        }
    }
    cout<<"Total number of times the word was found: "<< count<<endl;
    
    cout<<"Please type another word to replace the word you sought to find: ";
    cin>>newWord;

    int lengthOfNewWord = newWord.size();
    int difInSizes = lengthOfNewWord - wordLength;
    for(int i = 0; i < posOfWords.size(); i++){
        paragraph.erase(posOfWords.at(i), wordLength);
        paragraph.insert(posOfWords.at(i), newWord);
        for(int j = 1; j< posOfWords.size(); j++){
            posOfWords[j] = posOfWords.at(j) + difInSizes;
        }
    }
    cout<<"Here is the new paragraph\n";
    cout<<paragraph<<endl;

    return 0;




}