#include <iostream>

using namespace std;

template<typename  T>   // 模板声明，其中 T 为类型参数
class CompareSS
{
public:
    CompareSS(T a, T b) {
        x = a;
        y = b;
    }

    T maxFunc() {
        return (x > y ? x :y);
    }

private:
    int x, y;
};

int main() {

    // 用类木板定义对象，此时T被int参数化替代
    CompareSS<int> obj1(30, 90);
    cout << "最大值为: " << obj1.maxFunc() << endl;

    CompareSS<double> obj2(30.98, 90.56);
    cout << "最大值为: " << obj2.maxFunc() << endl;

    return 0;
}