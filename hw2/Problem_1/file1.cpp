#include "file1.hpp"

namespace std1 {
    int diceRoll() {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1,6);
        int roll = distribution(generator);
        return roll; 
    }

    float asPercentage(float size, int frequency) {
        float percentage = frequency / size;
        return percentage;
    }

    int frequency(const vector<int> rolls, int diceNumber) {
        int count = 0;
        int sizeOfVector = rolls.size();
        for(int i = 0; i < sizeOfVector; i++) {
            int j = rolls[i];
            switch(j == diceNumber) {
                case true:
                count++;
                break;
                case false:
                break;
            }
        }
        return count;
    }

    vector<int> diceRolls(int rolls) {
        vector<int> rollVector;
        for(int i = 0; i < rolls; i++) {
            int roll = diceRoll() + diceRoll();
            rollVector.push_back(roll);
        }
        return rollVector;
    }
}
