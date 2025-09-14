#include <iostream>

using namespace std;

class CTestA
{
public:
    CTestA() {
        x = 0;
        y = 0;

        cout << "初始化静态局部对象." << endl;
    }

    CTestA(double a) {
        x = a;
        y = 0;
        
        cout << "初始化全局对象." << endl;
    }

    CTestA(double a, double b) {
        x = a;
        y = b;

        cout << "初始化局部对象." << endl;
    }

private:
    double x, y;

};

CTestA objb(88.8);  // 全局对象初始化优先级最高，排行在第一

void FuncTest() {
    cout << "程序开始进入 FuncTest() 函数." << endl << endl;

    CTestA objc(10, 20);

    static CTestA objd;         // 初始化局部静态对象
}

int main() {

    cout << "\n程序开始执行 --> main()函数\n\n";

    CTestA obja(4.5, 6.5);      // 定义局部对象

    FuncTest();

    return 0;
}