/*  This program should determine if a number is a prime or composite number 
    The program should ask user for a number 'num'
    If 'num' is 0 or 1, print "num is not prime or composite"
    For any value > 1, print "num is a prime number" or "num is a composite number" depending on the number */

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include<iosteam>

int main(void){
    int num,i;
    bool factor_found = False;
    cout<<"Enter Number:\n";
    cin>>num;
    if(num == 0 && num ==1):
        cout<<num<<" is not prime or composite"
    for (i = 2, i<num, i++);{
        if num%i == 0:
            factor_Found = True
            break;
    }
    if not factor_found:
        cout<<"is a composite number\n";
    else:
        cout<<"is a prime number\n")
}
