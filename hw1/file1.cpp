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

/**
 * added namespace std; at the top
 * 
 * List of all changes from top of code to bottom:
 * Changed starting product values to 1 so you dont get stuck multiplying by 0. Sum in initialized to start at 0. Initialized limit and products as ints.
 * 
 * added int in front of i and changed colons to semicolons since this inst a while loop. Loop also starts at 1 since multiplying by 0 ruins the even_prod
 * 
 * changed how i is even or odd by using modulo and ==. then the product is multiplied by i. 
 * 
 * removed \n and a sneaky closed paren at the cout<<"The sum" line.
 * 
 * started the alphabet at z and worked down, which meant flipping  <= to >=. Defined a new char, ch, to represent the uppercase version of c. changed i to c to make sense and flipped the spacing order to start with a letter and not a space.
*/

#include <iostream>
using namespace std; // added this to include std

int main(){
    int limit = 10, even_product = 1, odd_product = 1, sum = 0; // changed starting product values to 1 so u dont get stuck multiplying by 0. made sum initialized at 0
    char c;

    cout<<"The value of limit is "<< limit<<endl;
    for(int i = 1; i <= limit; i++){  // added int in front of i and changed the colons to semicolons. not a while loop. started at 1 and not 0
       if(i % 2 == 0){ // changed it to modulo and ==, faulty logic constructors
           even_product = even_product * i; // changed this to multiply the current i by even product
       }   
        if(i % 2 == 1){ // changed ** to modulo
           odd_product = odd_product * i; // changed this to multiply the current i by odd product
       }
        sum = even_product + odd_product;
    }
    cout<<"The Sum = "<< sum << endl; // removed close-paren. remvoed \n. remvoed "%d"
 
    for(c = 'z'; c >= 'a'; c= c - 2){ // starting char is at z, and goes to a. This also required flipped <= to >=
    char ch = toupper(c);
    	cout<< ch << " "; // changed i to c. flipped order so it starts with letter and not space.
    }
    
    return 0;
}

