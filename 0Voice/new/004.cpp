#include <iostream>
#include <string>

using namespace std;

class TestC
{
public:
    // 普通构造函数
    TestC(string s, int d) : _data(d), _str(s) {
        cout << "程序执行：普通构造函数的函数体" << endl;
    }

    // 委托构造函数
    TestC(int d) : TestC("测试 TestC(int d) ", d) {
        cout << "程序执行：委托构造函数 TestC(int d) 的函数体" << endl;
    }

    TestC(string s) : TestC(s, 123) {
        cout << "程序执行：委托构造函数 TestC(string s) 的函数体" << endl;
    }

    void printData() const {
        cout << "----------------------------" << endl;
        cout << "_str = " << _str << endl;
        cout << "_data = " << _data << endl;
        cout << "----------------------------" << endl;
    }

private:
    int _data;
    string _str;
};

int main() {
    TestC obj1("测试普通构造函数：TestC(string s, int d)", 250);
    obj1.printData();

    TestC obj2(890);
    obj2.printData();

    TestC obj3("测试 TestC(string s)");
    obj3.printData();

    return 0;
}