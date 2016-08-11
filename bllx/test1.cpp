#include <iostream>
using namespace std;

// 变量声明
extern int a,b;
extern int c;
extern float f;

int main(){
    int a,b;
    int c;
    float f;

    a = 10;
    b = 20;
    c = a + b;

    cout << c << endl;

    f = 70.0/3.0;

    return 0;
}
