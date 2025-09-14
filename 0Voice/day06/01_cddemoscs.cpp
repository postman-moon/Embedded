#include <iostream>

using namespace std;

class CTestA
{
public:
    CTestA(int a, int b) {
        x = a;
        y = b;

        cout << "x: " << x << ", y: " << y << endl;
    }

    CTestA(int a) {
        cout << "a: " << a << endl;
    }

    int sumxy() {
        return (x + y);
    }

private:
    int x, y;

};

int main() {

    CTestA obja(56, 90);    // 只要程序运行，自动会初始化构造函数（自己会找到带有两个参数的构造函数）

    cout << "x + y = " << obja.sumxy() << endl;

    CTestA objb(30000);

    return 0;
}