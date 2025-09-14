#include <iostream>

using namespace std;

int main() {

    for (const auto var : {54, 67, 90, 12, 53, 88, 77, 123, 54, 20})
        cout << var << " ";
    cout << endl;

    for (const auto str : {"ABC", "DEF", "GHI", "JKL"})
        cout << str << " ";
    cout << endl;

    return 0;
}