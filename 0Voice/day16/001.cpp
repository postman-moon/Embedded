#include <iostream>

using namespace std;

int main() {

    int x, y;

    cout << "请输入x, y的值:";
    cin >> x >> y;

    try {
        if (y == 0)
            throw -1;   // 抛出 -1 类型异常
        else if (x == 0)
            throw -1.0; // 抛出 -1.0 类型异常
        else
            cout << "x / y = " << x / y << endl;
    } catch (int e) {
        cout << "catch(int) :" << e << endl;
    } catch (double d) {
        cout << "catch(double) :" << d << endl;
    }

    return 0;
}