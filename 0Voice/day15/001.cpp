#include <deque>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main() {

    // 创建一个使用 list 容器作为基础容器空的 vq 容器适配器
    queue<int, list<int>> vq1;

    deque<int> d1{1, 2, 3, 4, 5};
    queue<int> vq2(d1);
    queue<int> vq3 = vq2;   // 等价 queue<int> vq3(vq2);

    

    return 0;
} 