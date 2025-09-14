#include <iostream>

using namespace std;

class CTestFriend
{
public:
    CTestFriend() {     // 默认的构造函数
        cout << "调用默认的构造函数CTestFriend::CTestFriend()." << endl; 
    }

    CTestFriend(int a, int b) { // 带有参数的构造函数
        x = a;
        y = b;

        cout << "x = " << x << ", y = " << y << endl;
    }

    int mulxy() {       // 普通成员函数
        return x * y;
    }

    friend int sumxy(CTestFriend &obj); // 友元函数 访问私有成员和保护成员

private:
    int x, y;

};

int sumxy(CTestFriend &obj) {
    return obj.x + obj.y;
}

int main() {
    CTestFriend obja;
    CTestFriend objb(50, 100);

    cout << "两个数字之积为: " << objb.mulxy() << endl;
    cout << "两个数字子和为: " << sumxy(objb) << endl;

    return 0;
}