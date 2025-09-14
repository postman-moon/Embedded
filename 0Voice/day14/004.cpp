#include <iostream>
#include <deque>

using namespace std;

int main() {

    // 定义一个空的容器
    deque<int> d1;

    // 向容器的尾部插入数字
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_back(40);
    d1.push_back(50);
    d1.push_back(60);
    d1.push_back(70);
    d1.push_back(80);
    d1.push_back(90);
    d1.push_back(100);


    // 输出 d1 容器的元素个数
    cout << "输出 d1 容器元素的个数为: " << d1.size() << endl;

    // 向 d1 容器头部添加数据元素值
    d1.push_back(888);

    // 输出容器所有元素值
    cout << "输出d1容器所有元素的值:" << endl;
    for (auto i = d1.begin(); i < d1.end(); i++) {
        cout << " " << *i << " ";
    }
    cout << endl;

    // 删除容器头部的数据元素值
    d1.pop_front();
    cout << "输出d1容器所有元素的值: " << endl;
    for (auto i = d1.begin(); i < d1.end(); i++) {
        cout << " " << *i << " ";
    }
    cout << endl;

    return 0;
}