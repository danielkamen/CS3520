/*
input validation:
input is what you expect it to be*/
#include <bitset>
#include <iostream>
#include <limits>
#include <sstream> 
using namespace std;

int main() {
    int x;
    if (cin >> x) // EXTRACTION OPERATOR
        cout << x << endl;
    else
        cout << "input error" << endl; // INSERTION OPERATOR

    // these three lines do samething
    //istringstream istr("1 2 3 4");
    // these two go together
    string str = "1 2 3 4";
    istringstream istr(str);


    /*
    istream::operator>>
    return type is an istream referance
    another way of saying when u call cin>>x, compile converts that into a function call that looks like this: cin& operator>>(cin& , x)
                    return cin referance  funtion name

ios:iostate and ios_base

Recommendation is: check bad bit first
    */
    /*
    int y;
    cin >> y;
    bitset<d> f_val(cin.rdstate());
    cout << f_val << endl;
*/
    

}