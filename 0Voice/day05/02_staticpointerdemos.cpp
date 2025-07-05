#include <iostream>
using namespace std;

class CTest
{
public:
    CTest(int x = 0) {
        i = x;
        icount ++;
    }

    void disp() {
        cout << "i = " << i << ", icount = " << icount << endl;
    }

private:
    int i;
    static int icount;

};


int CTest::icount = 0;

int main() {
    CTest obj1[100];
    CTest obj2[10];

    obj1->disp();

    return 0;
}