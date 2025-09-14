#include <iostream>

using namespace std;

class A
{
public:
    A() {
        cout << "调用基类A: 默认构造函数" << endl;
    }

    A(int a) {
        cout << "调用基类A: 构造函数" << endl;

        x = a;
    }

    ~A() {
        cout << "调用基类A: 析构函数" << endl;
    }

private:
    int x;
};

class B
{
public:
    B(int b) {
        cout << "调用基类B: 构造函数" << endl;

        y = b;
    }

    ~B() {
        cout << "调用基类B: 析构函数" << endl;
    }

private:
    int y;
};

class C : public A, public B
{
public:
    C(int a, int b) : A(a), B(100) {
        cout << "调用派生类C: 构造函数" << endl;

        z = b;
    }

    ~C() {
        cout << "调用派生类C: 析构函数" << endl;
    }

private:
    int z;
    A obj1;
};

int main() {
    C obj(10, 50);

    return 0;
}