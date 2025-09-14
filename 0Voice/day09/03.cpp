#include <iostream>

using namespace std;

class A
{
public:
    int x, y;

    A() {
        cout << "调用类A: 默认构造函数" << endl;
    }

    void print() {
        cout << "x = " << x << ", y = " << y << endl;
    }

protected:
    A(int a, int b) {   // 基类初始化
        cout << "调用类A: 带参构造函数" << endl;

        x = a;
        y = b;
    }

};

class B : public A
{
public:
    B (int a, int b, int c) : A(a, b) {     // 可以在派生类调用A 的构造函数
        cout << "调用类B: 带参构造函数" << endl;

        m = c;
    }

    void print() {
        cout << "x = " << x << ", y = " << y << ", m = " << m << endl;
    }

private:
    int m;
    A obj;      // 在派生类中也不可以定义 A 的对象，世纪上还是类外调用
};

int main() {
    B obj(1, 2, 3);
    obj.print();

    return 0;
}