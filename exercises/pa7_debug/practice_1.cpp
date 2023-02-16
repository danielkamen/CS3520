
// Program to check if the user-provided number is a palindrome
// Number of errors/bugs = 25


//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.


#include<iostream>

// error 1: forgot using namespace std;
using namespace std;

// error 5: func takes in an int
// error 6, should return a boolean
bool func(int x); 

// error 14: return type should be int
int main() {
        // error 16: removed the input = numm aspect, shoudl be int
        int input;
		  cout<<"enter an integer please "; 
                  // error 2: ,missing an input line
                  cin>> input;
                  // error 3 func labeled wrong
                  // error 4, took in weird value
                  //error 7: didnt instantiate returned value
                  bool returned_val;
      returned_val = func(input);
        if (!returned_val){ 
                // error 8: didnd't wrap words in text
                //error 9: forgot semicolon after endl
                cout<<"It is not a palindrome"<<endl;
        }
        else{
                cout<<"It is a palindrome"<<endl;
        }
		//error 10: forgot a semicolon after 0
		return 0;
}

//the return value of your func should be true / false only
// error 11: update return value to bool
// error 12: update inputs to only take in 1 int
bool func(int n)
{

        // error 13: changed float to int
        // error 15 forgot semicolon
        // error 16 didnt set given number to n
            int val = n;
            // error 21 forgot reverse value
            int reverse = 0;
            while (n > 0) {
                // error 19: remaineder logic wrong
                // error 20: wrong variable
                // error 22 wrong reverse logic
                reverse = (reverse * 10) + n % 10;
		// error 23: need ti go to the next digit place
                n = n / 10;
            }

                // error 18: flipped true and false results
                // error 24: wrong variable value
            if (val == reverse)  
            {
                    return true;
            }
            else
            {
                    return false;
                }
}

