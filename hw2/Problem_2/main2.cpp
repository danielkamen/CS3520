#include "file2.cpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;




int main() {
    vector<ScamWord> scamWords;

    // makes 30 ScamWord class types, which store a word and an int value
    ScamWord f1;
    ScamWord f2;
    ScamWord f3;
    ScamWord f4;
    ScamWord f5;
    ScamWord f6;
    ScamWord f7;
    ScamWord f8;
    ScamWord f9;
    ScamWord f10;
    ScamWord f11;
    ScamWord f12;
    ScamWord f13;
    ScamWord f14;
    ScamWord f15;
    ScamWord f16;
    ScamWord f17;
    ScamWord f18;
    ScamWord f19;
    ScamWord f20;
    ScamWord f21;
    ScamWord f22;
    ScamWord f23;
    ScamWord f24;
    ScamWord f25;
    ScamWord f26;
    ScamWord f27;
    ScamWord f28;
    ScamWord f29;
    ScamWord f30;

    f1.word = "urgent";
    f1.value = 3;
    scamWords.push_back(f1);
    f2.word = "verification";
    f2.value = 3;
    scamWords.push_back(f2);
    f3.word = "required";
    f3.value = 3;
    scamWords.push_back(f3);
    f4.word = "invoice";
    f4.value = 3;
    scamWords.push_back(f4);
    f5.word = "account";
    f5.value = 3;
    scamWords.push_back(f5);
    f6.word = "suspicious";
    f6.value = 3;
    scamWords.push_back(f6);
    f7.word = "activity";
    f7.value = 3;
    scamWords.push_back(f7);
    f8.word = "important";
    f8.value = 3;
    scamWords.push_back(f8);
    f9.word = "password";
    f9.value = 3;
    scamWords.push_back(f9);
    f10.word = "expire";
    f10.value = 3;
    scamWords.push_back(f10);
    f11.word = "action";
    f11.value = 2;
    scamWords.push_back(f11);
    f12.word = "label";
    f12.value = 2;
    scamWords.push_back(f12);
    f13.word = "post";
    f13.value = 2;
    scamWords.push_back(f13);
    f14.word = "document";
    f14.value = 2;
    scamWords.push_back(f14);
    f15.word = "postal";
    f15.value = 2;
    scamWords.push_back(f15);
    f16.word = "calculations";
    f16.value = 2;
    scamWords.push_back(f16);
    f17.word = "copy";
    f17.value = 2;
    scamWords.push_back(f17);
    f18.word = "statement";
    f18.value = 2;
    scamWords.push_back(f18);
    f19.word = "financial";
    f19.value = 2;
    scamWords.push_back(f19);
    f20.word = "notification";
    f20.value = 2;
    scamWords.push_back(f20);
    f21.word = "irs";
    f21.value = 1;
    scamWords.push_back(f21);
    f22.word = "delivery";
    f22.value = 1;
    scamWords.push_back(f22);
    f23.word = "ticket";
    f23.value = 1;
    scamWords.push_back(f23);
    f24.word = "no";
    f24.value = 1;
    scamWords.push_back(f24);
    f25.word = "ups";
    f25.value = 1;
    scamWords.push_back(f25);
    f26.word = "usps";
    f26.value = 1;
    scamWords.push_back(f26);
    f27.word = "fedex";
    f27.value = 1;
    scamWords.push_back(f27);
    f28.word = "fraud";
    f28.value = 1;
    scamWords.push_back(f28);
    f29.word = "fradulent";
    f29.value = 2;
    scamWords.push_back(f29);
    f30.word = "wrong";
    f30.value = 1;
    scamWords.push_back(f30);

    // initalizes common values for every scamWord
    for (int i = 0; i < scamWords.size(); i++) {
        scamWords[i].timesFound = 0;
        scamWords[i].wordPointTotal = 0;
        scamWords[i].lineFirstFoundOn = "Word wasn't found in file";
        // for loop that ensures every scam word is all lowercase
        for (int j = 0; j < scamWords[i].word.length(); ++j) {
            string word = scamWords[i].word;
            word[j] = tolower(word[j]);
        }

    }

    const string outfilePath = "output.txt";
    const string infilePath = "input.txt";

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
    //line.beginLine.end
    // Read input stream into stringstream buffer
    stringstream buffers;
    buffers << in.rdbuf();
    string line;

    // total number of words in file
    float wordCount;

    // loops through each line
    while (getline(buffers, line)) {
        stringstream lineStream(line);
        string token;
        // loops through each word/token
        while (lineStream >> token) {
            for (int i = 0; i < scamWords.size(); ++i) {
                // if the sus word was found
                for (int j = 0; j < token.length(); ++j) {
                    token[j] = tolower(token[j]);
                }
                //ensures every word is checked as lowercase
                if ((token) == (scamWords[i].word)) {
                    if (scamWords[i].timesFound == 0) {
                        scamWords[i].lineFirstFoundOn = line;
                    }
                    scamWords[i].timesFound++;
                    scamWords[i].wordPointTotal = scamWords[i].value * scamWords[i].timesFound;
                }

            }
            wordCount++;
        }
    }

    cout << "Hello TA, please scroll to the bottom to see my response to the last two questions asked for this problem :)" << endl;

    cout << endl;
    cout << endl;
    cout << "_______________________________________________________" << endl;
    cout << "Sum of scam word points: " << std1::sumOfSusWordPoints(scamWords) << endl;
    cout << endl;

    cout << "***********************************************************" << endl;
    float perScam = (std1::sumOfSusWords(scamWords) / wordCount) * 100;
    cout << "Percentage of words that are common in scam files: " << perScam << "%" << endl;
    cout << "***********************************************************" << endl;
    cout << endl;
    cout << "_______________________________________________________" << endl;
    cout << "_______________________________________________________" << endl;
    cout << "Summary of file: " << endl;
    for (int i = 0; i < scamWords.size(); ++i) {
        cout << "Sus Word:                      " << scamWords[i].word << endl;
        cout << "Was found on this line: " << endl;
        cout << scamWords[i].lineFirstFoundOn << endl;
        cout << "It was found:                  " << scamWords[i].timesFound << " times" << endl;
        cout << "Its individual word score was: " << scamWords[i].wordPointTotal << endl;
        cout << "________________________________________________________" << endl;
        cout << endl;
    }

    
    cout<<"this approach doesn't work very well. Its not accurate with scam emails who just have images with text in them. Also longer non-scam emails get a large score even if its not a scam email, due to the large number of words."<<endl;

    return 0;
}
