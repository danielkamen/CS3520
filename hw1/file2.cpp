// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 617, exchange = 424
Output : 
"I am calling to tell you to buy a subscription to Dogs Monthly Magazine!"
617-424-0001
617-424-0002
617-424-0003
...
617-424-9998
617-424-9999
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)
/*Biggest fixes were as followed:
including namespace std
fixing sytnax to what it really should be
adding a 4th for-loop
changed the digits type to ints.
*/

#include<iostream>
using namespace std; // added this line to include std
  
int main(){
   int digit1, digit2, digit3, digit4;
   int areaCode, exchange;
   cout<< "Hello, I am a telemarketing calling making program.\n";
   cout<< "Enter a three-digit area code "; // added a quotation before enter to close the string
   cin>>exchange;
   cout<<"Enter a three-digit exchange to call ";
   cin>>areaCode;
   for(digit1 = 0; digit1 < 10; digit1++){ // added semicolons. increment variable is digit1.
        for(digit2 = 0; digit2 < 10; digit2++){ // changed parameters to match logic in the above. line added semicolons. increment variable is digit2
             for(digit3 = 0; digit3 < 10; digit3++) {
                    for(digit4 = 0; digit4 < 10; digit4++) { // added a counted for-loop for the 4th digit, the ones places
                     cout<< "Dialing ("<< areaCode<<") "<< exchange<<" - ";
                     cout<< digit1;
                     cout<<digit2;
                     cout<<digit3;
                     cout<<digit4<<endl;
                     cout<< "I am calling to tell you to buy a subscription to Dogs Monthly!\n";
                    }
             }
        }
    }
    
   cout<< "\nCalls completed"<<endl;
   return 0;
}
