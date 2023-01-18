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

#include<iostream>
  
int main(){
   char digit1, digit2, digit3, digit4;
   int areaCode, exchange;
   std::cout<< "Hello, I am a telemarketing calling making program.\n";
   std::cout<< Enter a three-digit area code ";
   cin<<exchange;
   std::cout<<"Enter a three-digit exchange to call "
   std::cin>>areaCode;
   for(digit1 = 0: digit1 <= 10: ++digit2){
        for(digit2 = 9, digit2 >=0, --digit3){
            while(digit3 = 0. digit3 < 10. ++digit3)
                cout<< "Dialing ("<< areaCode<<") "<< exchange<<" - ";
                cout<< digit1,digit2<<digit3<<digit4<<endl;
                cout<< "I am calling to tell you to buy a subscription to Dogs Monthly!\n");
            }
        }
    }
    
   std::cout<< "\nCalls completed"<<endl;
   return;
}
