#include <iostream>

using namespace std;

class CTest
{
public:
    CTest(int a) {
        x = a;
        y = y + x;
    }

    static void disp(CTest obj) {
        cout << "x = " << obj.x << ", y = " << y << endl;
    }

private:
    int x;
    static int y;   // 静态数据成员
};

int CTest::y = 10;

int main() {
    CTest obj1(5), obj2(10);

    CTest::disp(obj1);
    CTest::disp(obj2);


    return 0;
}