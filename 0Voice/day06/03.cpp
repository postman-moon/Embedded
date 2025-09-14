#include <iostream>

using namespace std;

class CTestA
{
public:
    CTestA() {
        cout << "调用缺省构造函数" << endl;
    }

    void setxy(int a, int b) {
        x = a;
        y = b;
    }

    void dispxy() {
        cout << "x: " << x << ", y: " << y << endl;
    }

private:
    double x, y;
};

int main() {

    CTestA obja, objb;      // 产生对象时，自动调用缺省的构造函数，不赋值

    obja.setxy(40, 90);

    cout << "obja对象结果为: " << endl;
    obja.dispxy();

    cout << "objb对象结果为: " << endl;
    objb.dispxy();

    return 0;
}