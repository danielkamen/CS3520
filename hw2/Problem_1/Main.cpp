#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

#include "file1.cpp"

using namespace std;

int main() {
    // gets the vector of rolls
vector<int> rolls = std1::diceRolls(36000);

// gets the frequency of each number
int twoRoll = std1::frequency(rolls, 2);
int threeRoll = std1::frequency(rolls, 3);
int fourRoll = std1::frequency(rolls, 4);
int fiveRoll = std1::frequency(rolls, 5);
int sixRoll = std1::frequency(rolls, 6);
int sevenRoll = std1::frequency(rolls, 7);
int eightRoll = std1::frequency(rolls, 8);
int nineRoll = std1::frequency(rolls, 9);
int tenRoll = std1::frequency(rolls, 10);
int elevenRoll = std1::frequency(rolls, 11);
int twelveRoll = std1::frequency(rolls, 12);


// gets the percentage of dice rolls
float size = (float) rolls.size();
float twoPer = std1::asPercentage(size, 2);
float threePer = std1::asPercentage(size, 3);
float fourPer = std1::asPercentage(size, 4);
float fivePer = std1::asPercentage(size, 5);
float sixPer = std1::asPercentage(size, 6);
float sevenPer = std1::asPercentage(size, 7);
float eightPer = std1::asPercentage(size, 8);
float ninePer = std1::asPercentage(size, 9);
float tenPer = std1::asPercentage(size, 10);
float elevenPer = std1::asPercentage(size, 11);
float twelvePer = std1::asPercentage(size, 12);


cout<<"-------------------------------------------"<<endl;
cout<<"Tally of 2's  rolled: "<<twoRoll<<"     As percentage: "<<twoPer<<endl;
cout<<"Tally of 3's  rolled: "<<threeRoll<<"     As percentage: "<<threePer<<endl;
cout<<"Tally of 4's  rolled: "<<fourRoll<<"     As percentage: "<<fourPer<<endl;
cout<<"Tally of 5's  rolled: "<<fiveRoll<<"     As percentage: "<<fivePer<<endl;
cout<<"Tally of 6's  rolled: "<<sixRoll<<"     As percentage: "<<sixPer<<endl;
cout<<"Tally of 7's  rolled: "<<sevenRoll<<"     As percentage: "<<sevenPer<<endl;
cout<<"Tally of 8's  rolled: "<<eightRoll<<"     As percentage: "<<eightPer<<endl;
cout<<"Tally of 9's  rolled: "<<nineRoll<<"     As percentage: "<<ninePer<<endl;
cout<<"Tally of 10's  rolled: "<<tenRoll<<"     As percentage: "<<tenPer<<endl;
cout<<"Tally of 11's  rolled: "<<elevenRoll<<"     As percentage: "<<elevenPer<<endl;
cout<<"Tally of 12's  rolled: "<<twelveRoll<<"     As percentage: "<<twelvePer<<endl;

cout<<"__________________________________________"<<endl;


return 0;

}