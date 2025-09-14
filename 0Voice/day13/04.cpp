#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream inFile;
    inFile.open("demo.txt", ios::in);
    if (inFile) {
        cout << "demo.txt 文件打开成功." << endl;

        inFile.close();
    } else {
        cout << "demo.txt 文件打开失败." << endl;

        return 1;
    }

    ofstream outFile;
    outFile.open("outdemo.txt", ios::out);
    if (outFile) {
        cout << "outdemo.txt 文件打开成功." << endl;

        outFile.close();
    } else {
        cout << "outdemo.txt 文件打开失败." << endl;

        return 1;
    }

    fstream ioFile;
    ioFile.open("iodemo.txt", ios::in | ios::out | ios::trunc);

    if (ioFile) {
        cout << "iodemo.txt 文件打开成功." << endl;
        ioFile.close();
    } else {
        cout << "iodemo.txt 文件打开失败." << endl;


    }

    return 0;
}
