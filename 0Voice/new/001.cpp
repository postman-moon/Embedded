#include <iostream>

using namespace std;

int main() {

    auto var1 = 250;
    decltype(199.88) var2;

    cout << "var1 占据字节个数: " << sizeof(var1) << endl;
    cout << "var2 占据字节个数: " << sizeof(var2) << endl;

    return 0;
}