#include <deque>
#include <iostream>
#include <queue>

using namespace std;

int main() {

    // 构建一个 queue 容器适配器
    deque<int> d1{11, 22, 33, 44, 55};
    queue<int> qd(d1);  // 11, 22, 33, 44, 55

    // 求出 qd存储元素的个数
    cout << "输出qd容器元素个数为: " << qd.size() << endl;

    // 输出 qd 容器所有元素的值
    while (!qd.empty()) {
        cout << qd.front() << "\t";

        // 访问过的元素出队列
        qd.pop();
    }
    cout << endl;

    // 求出 qd 存储元素的个数
    cout << "输出 qd 容器元素个数为: " << qd.size() << endl;

    return 0;
}