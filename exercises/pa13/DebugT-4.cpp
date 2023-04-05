// Debug T-5
/* Calculator class uses template class to perform arithmetic operations on different types of data.
 *  It also has function to determine which value is greater which return a boolean type.
 */

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>

using namespace std;
// class to perform various operations on two variables of type T
template <class T>
class Calculator
{
private:
    T num1;
    T num2;

public:
    Calculator(T n1, T n2);
    T add();
    T subtract();
    T multiply();
    T divide();
    bool isgreater();
};

template <class T>
Calculator<T>::Calculator(T n1, int n2)
{
    num1 = n1;
    num2 = n2;
}

template <class T>
Calculator<T>::add()
{
    return num1 + num2;
}

template <class T>
Calculator<T>::subtract()
{
    return num1 - num2;
}

template <class T>
T Calculator<T>::multiply(T n1, T n2)
{
    return n1 * n2;
}

template <class T>
T Calculator<T>::divide()
{
    return num1 % num2;
}

template <class T>
T Calculator<T>::isgreater()
{
    if (num1 > num2)
        return true;
    else
        return false;
}

int main()
{
    Calculator<int> calc(10, 4); // int operations
    cout << calc.add() << endl;
    cout << calc.subtract() << endl;
    cout << calc.multiply() << endl;
    cout << calc.divide() << endl;
    cout << std::boolalpha << calc.isgreater() << endl;

    Calculator<double> calc2(10.234, 4.235); // double operations
    cout << calc2.add() << endl;
    cout << calc2.subtract() << endl;
    cout << calc2.multiply() << endl;
    cout << calc2.divide() << endl;
    cout << std::boolalpha << calc2.isgreater() << endl;

    Calculator<string> calc3("Hello", 1); // string operations
    cout << calc3.add() << endl;
    cout << std::boolalpha << calc3.isgreater() << endl;
    return 0;
}
