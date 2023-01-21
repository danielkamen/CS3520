

// THEY GOT SCAMMED!!!!!!!!




#include <iostream>
#include <iomanip>
#include <cmath> // standard math library

// year date 1626 for 24 and put it in bank
// 397 years, compare interest rates from 2 -12%
using namespace std;

int main()
{
   double amount; // amount on deposit at end of each year
   double principal = 24.0; // initial amount before interest
   int rate = 2; // annual interest rate
   int year = 397; // how long was it compounded for

   // display headers
   cout << "Rate" << setw( 26 ) << "Earnings" << endl;

   // set floating-point number format
   cout << fixed << setprecision( 2 );

   // calculate amount on deposit for each of ten years
   for (rate; rate <= 12; ++rate ) 
   {
      // calculate new amount for specified year
      amount = principal * pow( (1.0 + (rate * 0.01)), year );

      // display the year and the amount
      cout << setw( 4 ) << rate<< "%" << setw( 25 ) << amount << endl;
   } // end for 
} // end main


