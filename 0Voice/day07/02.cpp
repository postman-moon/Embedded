#include <iostream>

using namespace std;

class CTestFriend
{
public:
    CTestFriend() {
        cout << "调用默认的构造函数CTestFriend::CTestFriend()." << endl; 
    }

    CTestFriend(int a, int b) {
        x = a;
        y = b;
    }

    int getx() {
        return x;
    }

    int gety() {
        return y;
    }

    int sum() {
        return x + y;
    }

    friend int sum(CTestFriend &obj);

private:
    int x, y;

};

int sum(CTestFriend &obj) {
    return obj.x + obj.y;
}

int sumxy(CTestFriend &obj) {
    return obj.getx() + obj.gety();
}

int main() {

    CTestFriend obj1(10, 20), obj2(100, 200), obj3(1000, 2000);

    cout << "obj1.sum(): " << obj1.sum() << endl;
    cout << "obj2.sum(): " << sum(obj2) << endl;
    cout << "obj3.sumxy(): " << sumxy(obj3) << endl;

    return 0;
}