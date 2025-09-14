#include <iostream>

#include <array>

using namespace std;

int main() {
    std::array<int, 5> values{};

    // 初始化 values 容器
    for (int i = 0; i < values.size(); i++) {
        values.at(i) = i;
    }

    // 通过 get() 重载函数输出指定位置元素值
    cout << "输出结果为: " << get<4>(values) << endl;

    return 0;
}