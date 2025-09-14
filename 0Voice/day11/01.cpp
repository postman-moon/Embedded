#include <iostream>

using namespace std;

class A
{
public:
    int x;

    A(int a = 0) {
        x = a;
    }

    void print() {
        cout << "调用类A的print()函数" << endl;
        cout << "x = " << x << endl;
    }
};

class B
{
public:
    int x;
    
    B(int a = 0) {
        x = a;
    }

    void print() {
        cout << "调用类B的print()函数" << endl;
        cout << "x = " << x << endl;
    }
};

class C
{
public:
    int x;

    C(int a = 0) {
        x = a;
    }

    void print() {
        cout << "调用类C的print()函数" << endl;
        cout << "x = " << x << endl;
    }
};

class D : public A, public B, public C
{
public:
    int d;

    D(int b = 0) {
        d = b;
    }

public:
    void setx(int a) {
        A::x = a;
    }

    void setd(int b) {
        d = b;
    }

    int getd() {
        return d;
    }
};

int main() {

    D obj;
    obj.C::print();

    return 0;
}