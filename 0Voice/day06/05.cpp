#include <iostream>

using namespace std;

class CTestA
{
public:
    CTestA() {
        cout << "调用缺省的构造函数." << endl;
    }

    CTestA(double a, double b) {
        x = a;
        y = b;

        cout << "调用带参的构造函数." << endl;
    }

    ~CTestA() {
        cout << "调用析构函数." << endl;
    }

private:
    double x, y;
};

int main() {

    CTestA obj1;
    CTestA obj2(5.6, 70.8);
    CTestA obj3(10, 20);

    return 0;
}