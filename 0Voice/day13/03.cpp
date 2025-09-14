#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const char *str = "http://www.163.com";

    // 我们要创建一个fstream类的对象
    fstream fs;

    // 将 demo.txt 文件和fs文件流建立关联
    fs.open("demo.txt", ios::out);

    fs.write(str,  100);

    fs.close();

    return 0;
}