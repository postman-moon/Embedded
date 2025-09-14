#include <fstream>
#include <iostream>


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

    ifstream inFile("student.dat", ios::in | ios::binary);      // 二进制读方法打开此文件

    if (!inFile) {
        cout << "打开失败" << endl;
        return 0;
    } else {
        cout << "打开文件成功" << endl;
    }

    while (inFile.read((char *)&stu,  sizeof(stu))) {
        cout << stu.no << "," << stu.name << "," << stu.age << endl;
    }

    inFile.close();

    return 0;
}