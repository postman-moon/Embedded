#include <iostream>
#include <fstream>

using namespace std;

class student
{
public:
    int no;
    char name[10];
    int age;
};

int main() {
    student stu;
    ofstream outFile("student.txt", ios::out | ios::binary);

    if (!outFile) {
        cout << "打开文件 student.txt 失败" << endl;
        outFile.close();
    } else {
        cout << "打开文件 student.txt 成功" << endl;
    }

    while (cin >> stu.no >> stu.name >> stu.age) {
        outFile.write((char *)&stu,  sizeof(stu));
    }

    outFile.close();

    return 0;
}