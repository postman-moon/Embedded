#include <iostream>

using namespace std;

class CTestA
{
public:
    CTestA() {  // 缺省构造函数
        x = 0;
        y = 0;

        cout << "调用缺省构造函数" << endl;
    }

    CTestA(double a, double b) {
        x = a;
        y = b;

        cout << "调用带参构造函数" << endl;
    }

    void dispxy() {
        cout << "x: " << x << ", y: " << y << endl;
    }

private:
    double x, y;

};

int main() {

    CTestA *pobja, *pobjb;  // 创建两个对象指针

    pobja = new CTestA;     // 用new动态开辟存储空间，调用缺省构造函数
    pobjb = new CTestA(200, 800);   // 用new动态开辟存储空间，调用带参构造函数

    pobja->dispxy();
    pobjb->dispxy();

    delete pobja;
    delete pobjb;   // 用 delete 释放动态开辟存储空间

    return 0;
}