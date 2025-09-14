#include <iostream>
#include <deque>

using namespace std;

int main() {

    // 创建 deque 容器，没有任何数据元素
    deque<int> d1;

    // 创建 deque 容器且有 50 个元素
    deque<int> d2(50);

    // 创建一个具有 9 个元素的 deque 容器，并且进行初始化值
    deque<int> d3(9, 888);

    // 容器之间可以赋值
    deque<int> d4(10);
    deque<int> d5(d4);

    return 0;
}