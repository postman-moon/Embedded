#include <iostream>

using namespace std;

class CTestFClassA
{
public:
    CTestFClassA(double a, double b) {
        x = a;
        y = b;
    }

    double getx() {
        return x;
    }

    double gety() {
        return y;
    }

    friend class CTestFClassB;

private:
    double x, y;
};

class CTestFClassB
{
public:
    CTestFClassB(int n = 1) {
        k = n;
    }

    void disp(CTestFClassA &obj) {
        cout << "结果为: " << obj.x + obj.y + k << endl;
    }

private:
    double k;
};

int main() {

    CTestFClassA obj1(10, 20), obj2(200, 200);
    CTestFClassB objb(20);
    objb.disp(obj1);
    objb.disp(obj2);

    return 0;
}