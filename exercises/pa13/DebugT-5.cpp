// The goal of this debug execrice is to understand the concept of object slicing.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

// Expected output -
// Name: tesla model Year: 2019
// Name: Hyundai model Year: 2020 Mileage: 23
// Name: Ford model Year: 2012 Miles driven: 20000
// Name: Ford model Year: 2017 Miles driven: 10000

#include <iostream>

using namespace std;

class car
{
private:
    string name;
    int modelYear;
    void assign(const car &c)
    {
        name = c.name;
        modelYear = c.modelYear;
    }

public:
    car(const string &n, const int my) : name(n), modelYear(my) {}

    virtual void print() const
    {
        cout << "Name: " << name << " model Year: " << modelYear << endl;
    }

    virtual const car &operator=(const car &c)
    {
        name = c.name;
        modelYear = c.modelYear;
        return *this;
    }
};

class sedan : public car
{
private:
    int mileage;

public:
    sedan(const string &n, const int my, const int m) : car(n, my), mileage(m) {}

    virtual void print() const
    {
        cout << "Name: " << name << " model Year: " << modelYear << " Mileage: " << mileage << endl;
    }
};

class suv : public car
{
    int miles;

public:
    suv(const string &n, const int my, const int m) : miles(m) {}

    virtual void print() const
    {
        cout << "Name: " << name << " model Year: " << modelYear << " Miles driven: " << miles << endl;
    }

    virtual const suv &operator=(const car c)
    {
        if (const suv *b = dynamic_cast<const suv *>(&c))
        {
            assign(*b);
        }
        return *this;
    }

protected:
    void assign(const suv &c)
    {
        car::assign(c);
        miles = c.miles;
    }
};

void printCarInfo(const car c)
{
    c.print();
}

int main()
{
    car tesla = car("tesla", 2019);
    sedan hyundai = sedan("Hyundai", 2020, 23);
    suv ford = suv("Ford", 2012, 20000);

    printCarInfo(tesla);
    printCarInfo(hyundai);

    car &ref = ford;
    printCarInfo(ref);
    suv ford2 = suv("Ford", 2017, 10000);
    ref = ford2;
    printCarInfo(ref);
    return 0;
}