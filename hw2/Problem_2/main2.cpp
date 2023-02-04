#include "file2.cpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#define EXIT_FAILURE -1

#include "file2.cpp"

using namespace std;




int main() {
vector<ScamWord> scamWords;
vector<string> linesFound;

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
f5.word = "help";
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
  // Read input stream into stringstream buffer
  stringstream buffers;
  buffers << in.rdbuf();
  string line;
 

// loops through each line, and scans it
while (getline(buffers, line)) {
    stringstream lineStream(line);
    string token;
    // Parse word by word
    while (lineStream >> token) {
        std1::scanFileScammer(token, scamWords, line);
}
}

cout<<"_______________________________________________________"<<endl;
cout<<"Sum of scam word points: "<<std1::sumOfSusWords(scamWords)<<endl;

cout<<"_______________________________________________________"<<endl;
cout<<"Summary of file: "<<std1::outputOfText(scamWords)<<endl;



}
