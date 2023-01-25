#include <iostream>
#include <string>
using namespace std;

// People: David Cui && Daniel Kamen

/**
 * Share your observations about the memory addresses of {static and non-static} member variables. Explain what you think they mean?
 * The memory addresses of the static member variables, after the 0x, are all 6 digits long.
 * The memory addresses of the non-static member variables, after the 0x, are all 12 digits long. Double that of the static variables.
 * I think this means that since the static variables are defined once and stay the same after their decleration, they need less memory allocated to them. Whereas the non-static variables can be changed, so they need to store more data representing that, and to account for the change to require more memory.
 *
*/
class Student {
private:
    static string first_name;
    string last_name;
public:
    static int id;
    string address;
    void print();

    // setters
    void setFirst(string fname) {
        Student::first_name = fname;
    }
    void setLast(string name) {
        last_name = name;
    }

    //getters
    string get_first() { return Student::first_name; }
    string get_last() { return last_name; }

};

int Student::id = 1;
string Student::first_name = "bob";

// print method that prints a students MEMBER VARIABLES memory addresses
void Student::print() {
    cout << "memory address for id: " << &id << endl;
    cout << "memory address for address: " << &address << endl;
    cout << "memory address for first_name: " << &first_name << endl;
    cout << "memory address for last_name: " << &last_name << endl;
};


// print method that prints a STUDENTS memory address
void print(Student stu) {
    cout << "Memory address for the student object: " << &stu << endl;
}


int main() {


    Student first;
    Student second;

    first.setLast("Ross");
    first.address = "4000 hello st";
    first.print();
    print(first);

    second.setLast("Jenkins");
    second.address = "4001 hello st";
    second.print();
    print(second);



}