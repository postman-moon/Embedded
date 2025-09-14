#include <iostream>

using namespace std;

namespace OneSpace {    // 第一命名空间
    void print() {
        cout << "执行OneSpace命名空间的print()函数" << endl;
    }
}

namespace TwoSpace {    // 第二命名空间
    void printf() {
        cout << "执行TwoSpace命名空间的print()函数" << endl;
    }
}

using namespace OneSpace;

int main() {

    // 调用第一命名空间中的print函数
    OneSpace::print();
    // 调用第二命名空间中的print函数
    TwoSpace::printf();

    print();

    return 0;
}