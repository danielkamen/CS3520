#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

class MyString {
    unique_ptr<char[]> str;

public:
    MyString() : str(new char[1]) { // Default Constructor
        str[0] = '\0';
    }


 MyString(unique_ptr<char[]>& val) : str(move(val)) {
        if (val == nullptr) {
            str.reset(new char[1]);
            str[0] = '\0';
        } else {
            int length = strlen(val.get()) + 1;
            str.reset(new char[length]);
            strcpy(str.get(), val.get());
             str[strlen(val.get())] = '\0';
            cout << "The given string is: " << str.get() << endl;
        }
    }


    MyString(const MyString& source) { // Copy Constructor
        int length = strlen(source.str.get()) + 1;
        str.reset(new char[length]);
        strcpy(str.get(), source.str.get());
        str[length - 1] = '\0';
    }

    MyString(MyString&& source) noexcept { // Move Constructor
        str = move(source.str);
    }

    ~MyString() = default; // Destructor
};

int main(void) {

//unique_ptr<Test> a(new Test(1));
//unique_ptr<Test[]> b(new Test[2]{2,3});
//cout<<"ID:"<<a->get_id()<<endl;
//cout<<"ID:"<<b[0].get_id()<<endl;


/*deleting lines 16-19 produces a seg fault*/
/* line 57, wtf how do i do?*/
    cout << "Start!" << endl;
    unique_ptr<MyString> a(new MyString());
    unique_ptr<char[]> hello(new char[6]{'H', 'e', 'l', 'l', 'o', '\0'});
    unique_ptr<MyString> b(new MyString(hello));
    unique_ptr<MyString> c(a);
   

    cout << "Bye" << endl;
}
