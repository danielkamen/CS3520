#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

namespace std1 {
    // function that simulate ONE diceroll
    int diceRoll();
    // returns the #of times rolled as a %
    float asPercentage(const vector<int> rolls, int frequency);
    // returns the frequency of how many times a number was rolled
    int frequnecy(const vector<int> rolls, int diceNumber);
    // makes a vector comprised of the sum of two dice rolls, #n times (rolls)
    vector<int> diceRolls(int rolls);
}