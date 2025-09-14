#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {

    // 创建存储的 double 数据类型的一个 vector 容器 --> v1
    vector<double> v1;

    // 创建容器 v2 且同时给它进行初始化元素的个数
    vector<double> v2{34, 65, 78, 90, 28, 56, 98, 77, 81, 19};

    // 创建vector容器，指定元素个数为 50
    vector<int> v3(50);

    // 创建 vector 容器，它拥有 10 个字符为 'A'
    vector<char> v4(10, 'A');

    // 将 v4 赋值给 v5
    vector<char> v5(v4);

    int a[] = {10, 20, 30};
    vector<int> v6(a, a + 1);   // v6 将会保存10, 20

    vector<int> v7{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v8(begin(v7), begin(v7) + 3);   // v8 将会保存为: 1, 2, 3

    return 0;
}