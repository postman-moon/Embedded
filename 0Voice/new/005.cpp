#include <iostream>

using namespace std;

struct A
{
    void func(double d) {
        cout << "基类A: " << d << endl;
    }
};

struct B : A {
    using A::func;  // C++ 11标准当中利用 using 关键字特点，是构造函数可以被“继承”

    void func(int i) {
        cout << "派生类B: " << i << endl;
    }
};

int main() {
    A a;
    a.func(78);

    B b;
    b.func(87);

    return 0;
}