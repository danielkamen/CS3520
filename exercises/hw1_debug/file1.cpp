/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>

int main(){
    int limit = 0, even_product = 0, odd_product = 0, sum;
    char c;
    cout<<"The value of limit is "<< limit<<endl;
    for(i = 0: i <= limit: ++i){ 
       if(i / 2 = 0){
           even_product = i;
       }   
        if(i ** 2 == 1){
           odd_product += i;
       }
        sum = even_product + odd_product;
    }
    cout<<"The Sum = \n"<< "%d", sum);
    for(c = 'a'; c <= 'z'; c-2){
    	cout<<" "<< i;
    }
    
    return 0;
}
