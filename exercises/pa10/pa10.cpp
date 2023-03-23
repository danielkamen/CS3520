#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <forward_list>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
class Employee {
private:
    string employee_name;
    string employee_email;
    string designation;
    int salary;
    int group_id;

public:
    void setEmployeeName(string name) { (*this).employee_name = name; }
    string getEmployeeName() const { return (*this).employee_name; }

    void setEmployeeEmail(string email) { (*this).employee_email = email; }
    string getEmployeeEmail() const { return (*this).employee_email; }

    void setDesignation(string name) { (*this).designation = name; }
    string getDesignation() const { return (*this).designation; }

    void setSalary(int num) { (*this).salary = num; }
    int getSalary() const { return (*this).salary; }

    void setGroupNumber(int num) { (*this).group_id = num; }
    int getGroupNumber() const { return (*this).group_id; }

    friend istream& operator>> (istream& in, Employee& value);

    friend ostream& operator<< (ostream& out, const Employee& value);
};

class Group {
private:
    string group_name;
    int group_number;
    string focus_area;
    vector<Employee> employees;

public:
    void setGroupName(string name) { (*this).group_name = name; }
    string getGroupName() const { return (*this).group_name; }

    void setGroupNumber(int num) { (*this).group_number = num; }
    int getGroupNumber() const { return (*this).group_number; }

    void setFocusArea(string area) { (*this).focus_area = area; }
    string getFocusArea() const { return (*this).focus_area; }

    void addEmployee(const Employee& emp) { (*this).employees.push_back(emp); }
    vector<Employee> getLOE() const { return (*this).employees; }

    void addEmployeeList(const vector<Employee>& emp) { (*this).employees= emp; }

    vector<Employee> removeEmployee(const int& emp) {
        vector<Employee> temp = (*this).getLOE();
        temp.erase(temp.begin() + emp);
        return temp;
    }



    void setEmployeeList(const vector<Employee>& emp) { (*this).employees = emp; }

    Group operator-(const int& num);

    Group operator+(const Group& other);

    Group operator/(const int& dummyValue);

    friend istream& operator>> (istream& in, Group& value);

    friend ostream& operator<< (ostream& out, const Group& value);
};

Group Group::operator-(const int& num) {
    Group copy = *this;
    sort(employees.begin(), employees.end(),
        [](const Employee& left, const Employee& right) {
            return left.getSalary() > right.getSalary();
        });

    for (int i = 0; i < num; i++) {
        (*this).employees.pop_back();
    }
    return copy;
}

Group Group::operator+(const Group& other) {
    Group newOne;

    if (other.getLOE().size() > (*this).getLOE().size()) {
        newOne.setGroupName(other.getGroupName());
        newOne.setGroupNumber(other.getGroupNumber());
        newOne.setFocusArea(other.getFocusArea());
    }
    else {
        newOne.setGroupName((*this).getGroupName());
        newOne.setGroupNumber((*this).getGroupNumber());
        newOne.setFocusArea((*this).getFocusArea());
    }

    for (int i = 0; i < other.getLOE().size(); i++) {
        Employee tempO = other.getLOE().at(i);
        newOne.addEmployee(tempO);
    }

    for (int j = 0; j < (*this).getLOE().size(); j++) {
        Employee tempT = (*this).getLOE().at(j);
        newOne.addEmployee(tempT);
    }

    return newOne;
}

Group Group::operator/(const int& dummyValue) {
    Group newOne;

    newOne.setGroupName((*this).getGroupName() + "Split");
    int newGN = (*this).getGroupNumber() * 213;
    newOne.setGroupNumber(newGN);

    for (int i = 0; i < (*this).getLOE().size(); i++) {
        
        // removes every other from (*this) and adds it to newOne.
        if (i % 2 == 0) {
            Employee temp = (*this).getLOE().at(i);
            temp.setGroupNumber(newGN);
            newOne.addEmployee(temp);
            vector<Employee> tempList = (*this).removeEmployee(i);
            (*this).addEmployeeList(tempList);
        }
    }

    return newOne;
}


ostream& operator<<(ostream& out, const Group& value) {
    out << "focus area: " << value.focus_area << " name: " << value.group_name << " id: " << value.group_number << " employeees: "<<endl;
    for (int i = 0; i < value.employees.size(); i++) {
        out<< " "<< value.employees.at(i);
    }
    return out;
}


ostream& operator<<(ostream& out, const Employee& value) {
    out << "Designation: " << value.designation << " name: " << value.employee_name << " email: " << value.employee_email << "salary " << value.salary << "id: "<<value.group_id<< endl;
    return out;
}

istream& operator>> (istream& in, Group& value) {
    in >> value.group_name >> value.group_number >> value.focus_area;
    return in;
}

istream& operator>> (istream& in, Employee& value) {
    in >> value.employee_name >> value.employee_email >> value.designation >>value.salary >> value.group_id;
    return in;
}


int main(void) {

    vector<string> empNames = { "Emily", "Benjamin", "Olivia", "Ethan", "Sophia", "Jackson", "Ava", "Liam", "Isabella", "Noah" };


    vector<double> possibleSalaries = { 30000.0, 35000.0, 40000.0, 45000.0, 50000.0, 55000.0, 60000.0, 65000.0, 70000.0, 75000.0 };


    vector<string> dummyEmails;

    for (const auto& name : empNames) {
        dummyEmails.push_back(name + "@hehe.com");
    }

    vector<string> names;
    names.push_back("Apple");
    names.push_back("Amazon");
    names.push_back("FaceBook");
    names.push_back("Google");
    names.push_back("Bing");
    
    vector<Group> groups;

    for (int i = 0; i < 5; i++) {
        Group temp;
        temp.setGroupNumber(i);
        temp.setGroupName(names.at(i));
        temp.setFocusArea("tech");
        for (int j = 0; j < 10; j++) {
            Employee tempe;
            tempe.setEmployeeName(empNames.at(j));
            tempe.setSalary(possibleSalaries.at(j));
            tempe.setEmployeeEmail(dummyEmails.at(j));
            tempe.setDesignation(temp.getFocusArea());
            tempe.setGroupNumber(temp.getGroupNumber());
            temp.addEmployee(tempe);
        }
        groups.push_back(temp);
    }

    for (int w = 0; w < groups.size(); w++) {
        cout<<"_______________________________________________________________________"<<endl;
        cout<<groups.at(w);
        cout<<"_______________________________________________________________________"<<endl;
    }

cout<<"_______________________________________________________________________"<<endl;
    cout<<"Testing firing X employees (-) (of course its gonna be meta)"<<endl;
    cout<<groups.at(2)<<endl;
    cout<<"_______________________________________________________________________"<<endl;
    groups.at(2) - 8;
    cout<<"_______________________________________________________________________"<<endl;
    cout<<groups.at(2)<<endl;
cout<<"_______________________________________________________________________"<<endl;
cout<<"Testing a merger (+)"<<endl;
cout<<"I have it so the bigger company absorbs the smaller one (bye bye meta)"<<endl;
cout<<groups.at(2)+groups.at(4)<<endl;
cout<<"_______________________________________________________________________"<<endl;
cout<<"Testing a split (/)"<<endl;
cout<<"Group that leaves and makes their own comapny"<<endl;
cout<<groups.at(1)/2<<endl;
cout<<"_______________________________________________________________________"<<endl;
cout<<"The OGS who stayed begind"<<endl;
cout<<groups.at(1);

    return 0;
}
