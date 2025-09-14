#include <iostream>
#include <ostream>

using namespace std;

class CTest
{
public:
    CTest() : x(10) {

    }

    CTest operator--() {
        CTest obj;
        obj.x = --x;

        return obj;
    }

    // 括号中插入int参数，表示后缀计算方式
    CTest operator--(int) {
        CTest obj;
        obj.x = x--;

        return obj;
    }

    void disp() {
        cout << "x = " << x << endl;
    }


private:
    int x;
};

int main() {
    CTest obj1, obj2;
    cout << "输出结果1为: " << endl;
    obj1.disp();
    obj2.disp();

    obj2 = --obj1;
    cout << "输出结果2为: " << endl;
    obj1.disp();
    obj2.disp();

    obj2 = obj1--;
    cout << "输出结果3为: " << endl;
    obj1.disp();
    obj2.disp();

    return 0;
}