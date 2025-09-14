#include <iostream>

using namespace std;

class CTestA
{
public:
    CTestA(int a);              // 构造函数
    CTestA(const CTestA &obj);  // 拷贝构造函数
    ~CTestA();                  // 析构函数

    int getptr() {
        return *ptr;
    }

private:
    int *ptr;
};

CTestA::CTestA(int a) {
    cout << "调用构造函数." << endl;

    // 为指针分配内存空间
    ptr = new int;
    *ptr = a;
}

CTestA::CTestA(const CTestA &obj) {
    cout << "调用拷贝构造函数并为指针ptr分配空间" << endl;

    ptr = new int;
    *ptr = *obj.ptr;
};

CTestA::~CTestA() {
    cout << "释放内存空间." << endl;

    delete ptr;
}

void dispptr(CTestA obj) {
    cout << "ptr值为: " << obj.getptr() << endl;
}

int main() {

    CTestA obj(5600);
    dispptr(obj);

    return 0;
}