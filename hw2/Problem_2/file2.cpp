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

    int sumOfSusWords(vector<ScamWord> words) {
        int sum = 0;
        for (int i = 0; i < words.size(); ++i) {
            sum = sum + words[i].wordPointTotal;
        }
        return sum;
    }

}