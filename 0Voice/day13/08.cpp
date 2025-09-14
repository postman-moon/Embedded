#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    char ch;

    ifstream inFile("outdemo.txt", ios::out | ios::binary);

    if (!inFile) {
        cout << "outdemo.txt 文件打开失败." << endl;

        return -1;
    } else {
        cout << "outdemo.txt 文件打开成功." << endl;
    }

    while ((ch = inFile.get()) && ch != EOF) {
        cout << ch;
    }

    inFile.close();

    return 0;
}