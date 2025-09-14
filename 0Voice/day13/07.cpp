#include <iostream>
#include <fstream>

using namespace std;

int main() {

    char ch;

    ofstream outFile("outdemo.txt", ios::out | ios::binary);

    if (!outFile) {
        cout << "outdemo.txt 文件打开失败." << endl;
        return -1;
    } else {
        cout << "outdemo.txt 文件打开成功." << endl;
    }

    while (cin >> ch) {
        outFile.put(ch);
    }

    outFile.close();

    return 0;
}