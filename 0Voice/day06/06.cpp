#include <cstdlib>
#include <iostream>

using namespace std;

class CTestA
{
public:
    CTestA() {
        cout << "调用构造函数CTestA::CTestA()." << endl;
        pc = new int(10000);

        cout << *pc << endl;
    }

    ~CTestA() {
        delete pc;

        cout << "调用析构函数~CTestA::CTestA()." << endl;
    }

private:
    int *pc;
};

int main() {
    CTestA *p1 = new CTestA;
    CTestA *p2 = (CTestA *)malloc(sizeof(CTestA));

    delete p1;      // 动态归还堆的空间
    free(p2);

    return 0;
}