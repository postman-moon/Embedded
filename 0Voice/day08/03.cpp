#include <iostream>

using namespace std;

class CTestSS
{
public:
    CTestSS() : i(0) {

    }

    CTestSS operator++() {
        cout << "调用前置递增." << endl;

        CTestSS obj;
        obj.i = ++i;

        return obj;
    }

    // 括号中插入 int 表示后缀
    CTestSS operator++(int) {
        cout << "调用后置递增." << endl;

        CTestSS obj;
        obj.i = i++;

        return obj;
    }

    void disp() {
        cout << "i = " << i << endl;
    }

private:
    int i;
};

int main() {
    CTestSS obj1, obj2;

    cout << "输出结果1为: " << endl;
    obj1.disp();
    obj2.disp();

    // 调用运算符函数，然后将obj1的值赋值给obj2
    obj2 = ++obj1;
    cout << "输出结果2为: " << endl;
    obj1.disp();
    obj2.disp();

    obj2 = obj1++;
    cout << "输出结果3为: " << endl;
    obj1.disp();
    obj2.disp();

    return 0;
}