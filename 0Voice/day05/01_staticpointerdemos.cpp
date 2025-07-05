#include <iostream>

using namespace std;

class CTestA
{
public:
    CTestA(int a, int b, int c, int d) {
        i = a;
        j = b;
        x = c;
        y = d;
    }

    void dispijxy() {
        cout << "i = " << i << ", j = " << j << ", x = " << x << ", y = " << y << endl;
    }

private:
    int i, j;
    static int x, y;    // 定义静态数据成员
};

// 静态成员定义性说明
int CTestA::x = 0;
int CTestA::y = 0;

int main() {
    CTestA obj1(10, 20, 30, 40);
    obj1.dispijxy();

    CTestA obj2(100, 200, 300, 400);
    obj2.dispijxy();

    return 0;
}