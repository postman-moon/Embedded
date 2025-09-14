#include <iostream>

using namespace std;

class Box
{
public:
    Box() {
        l = 0;
        b = 0;
        h = 0;
    }

    void setl(double length) {
        l = length;
    }

    void setb(double breadth) {
        b = breadth;
    }

    void seth(double hight) {
        h = hight;
    }

    // 求体积
    double getv() {
        return l * b * h;
    }

    // 重载 + 运算符，用于把两个Box对象进行相加
    Box operator+(const Box &b) {
        Box box;

        box.l = this->l + b.l;
        box.b = this->b + b.b;
        box.h = this->h + b.h;

        return box;
    }

private:
    double l;   // 长度
    double b;   // 宽度
    double h;   // 高度
};

int main() {
    Box box1;           // 声明box1,类型为Box
    Box box2;
    Box box3;

    double dv = 0.0;    // 存储体积变量

    // 为第一个对象赋值 box1
    box1.setl(2.0);
    box1.setb(3.0);
    box1.seth(4.0);

    // 为第二个对象赋值 box2
    box2.setl(5.0);
    box2.setb(6.0);
    box2.seth(7.0);

    // 输出 box1 体积
    dv = box1.getv();
    cout << "box1 对象的体积为: " << dv << endl;

    // 输出 box2 体积
    dv = box2.getv();
    cout << "box2 对象的体积为: " << dv << endl;

    // 把两个对象相加，得到 box3
    box3 = box1 + box2;

    // 输出 box3 体积
    dv = box3.getv();
    cout << "box3 对象的体积为: " << dv << endl;

    return 0;
}