#include <iostream>

using namespace std;

class CTestA
{
public:
    CTestA(double a, double b) {
        x = a;
        y = b;

        cout << "调用带参的构造函数." << endl;
    }

    ~CTestA() {
        cout << "调用析构函数." << endl;
    }

    void dispxy() {
        cout << "x: " << x << ", y: " << y << endl;
    }

private:
    double x, y;
};

int main() {
    CTestA obj1(2, 3);
    obj1.dispxy();

    obj1 = CTestA(90, 20);
    obj1.dispxy();

    return 0;
}