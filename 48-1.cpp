#include<iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Constructor: Base" << endl; }
    virtual ~Base() { cout << "Destructor : Base" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Constructor: Derived" << endl; }
    ~Derived() { cout << "Destructor : Derived" << endl; }
};

void test1() {
    Base* Var = new Derived();
    delete Var;
}
struct stuff
{
    unsigned int field1 : 30;
    unsigned int : 2;
    unsigned int field2 : 4;
    unsigned int : 0;
    unsigned int field3 : 3;
};
void test2() {
    stuff sf;
    cout << sizeof(sf) << endl;
}
int main() {
    test2();
    return 0;
}