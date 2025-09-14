#include <iostream>

using namespace std;

class A
{
public:
    int z;  // 公有数据成员    

    A(int a, int b, int c) {
        x = a;
        y = b;
        z = c;

        cout << "调用类A带参的构造函数" << endl;
    }

    int getx() {
        return x;
    }

    int gety() {
        return y;
    }

    int getz() {
        return z;
    }

    void print() {
        cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    }

protected:
    int y;  // 保护数据成员

private:
    int x;  // 私有数据成员
};

class B : public A
{
public:
    B(int a, int b, int c, int d, int e) : A(a, b, c) {
        cout << "调用派生类B带参：构造函数" << endl;

        m = d;
        n = e;
    }

    void print() {
        cout << "x = " << getx() << ", y = " << y << ", z = " << z << ", m = " << m << ", n = " << n << endl;
    }

    int sum() {
        return getx() + y + z + m + n;
    }


private:
    int m, n;
};

int main() {

    // A obj(1, 2, 3);
    // obj.print();

    B obj(1, 2, 3, 4, 5);   // 派生类创建对象obj，且初始化参数 1 2 3 4 5
    obj.print();

    cout << "sum = " << obj.sum() << endl;
    cout << "x = " << obj.getx() << endl;
    cout << "y = " << obj.gety() << endl;
    cout << "z = " << obj.getz() << endl;

    return 0;
}