#include <iostream>
#include <vector>

using namespace std;

int main() {

    // 定义一个空的 vector 容器
    vector<char> vi;

    // 向容器中添加 S T L T E M P L A T E
    vi.push_back('S');
    vi.push_back('T');
    vi.push_back('L');
    vi.push_back('T');
    vi.push_back('E');
    vi.push_back('M');
    vi.push_back('P');
    vi.push_back('L');
    vi.push_back('A');
    vi.push_back('T');
    vi.push_back('E');

    // 输出容器 vi 元素的个数 size()
    cout << "元素个数为: " << vi.size() << endl;

    // 遍历容器
    cout << "输出 vi 容器数据元素: " << endl;
    for (auto i = vi.begin(); i < vi.end(); i++)
        cout << " " << *i << " ";
    cout << endl;

    // 插入数据元素到头部
    vi.insert(vi.begin(), 'V');

    cout << "输出 vi 容器数据元素: " << endl;
    for (auto i = vi.begin(); i < vi.end(); i++)
        cout << " " << *i << " ";
    cout << endl;

    // 插入数据元素到尾部
    vi.insert(vi.end(), 'I');

    cout << "输出 vi 容器数据元素: " << endl;
    for (auto i = vi.begin(); i < vi.end(); i++)
        cout << " " << *i << " ";
    cout << endl;

    cout << "输出vi容器首个元素为: " << vi.at(0) << endl;

    return 0;
}