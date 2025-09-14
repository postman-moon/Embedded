#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {

    set<string> mys;

    cout << "测试容器 mys 长度:" << mys.size() << endl;

    mys.insert("www.baidu.com");
    mys.insert("www.163.com");
    mys.insert("www.126.com");
    mys.insert("www.0vice.com");

    cout << "测试容器 mys 长度:" << mys.size() << endl;

    cout << "输出 mys 容器所有元素: " << endl;
    for (auto it = mys.begin(); it != mys.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}