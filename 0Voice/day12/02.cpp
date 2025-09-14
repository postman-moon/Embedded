#include <iostream>

using namespace std;

namespace OneSpace {
    void print() {
        cout << "执行OneSpace命名空间的print()函数" << endl;
    }

    namespace TwoSpace {
        void print() {
            cout << "执行TwoSpace命名空间的print()函数" << endl;
        }
    }

}

using namespace OneSpace::TwoSpace;

int main() {

    print();

    return 0;
}