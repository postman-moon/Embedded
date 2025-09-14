#include <iostream>

using namespace std;

int add(int a, int b) {
    cout << "调用整型类型" << endl;
    return a + b;
}

int add(char a, char b) {
    cout << "调用字符型类型" << endl;

    return a + b;
}

double add(double a, double b) {
    cout << "调用双精度型类型" << endl;

    return a + b;
}

int main() {

    cout << "两数相加: " << add(25, 82) << endl;
    cout << "两数相加: " << add('A', 'B') << endl;
    cout << "两数相加: " << add(89.9, 78.1) << endl;

    return 0;
}