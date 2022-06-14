#include <iostream>
using namespace std;

int main()
{
    int *p;
    int *q;
    int var;
    // =
    q = p = &var;
    cout << p << " " << q << endl; // 0x7ffdc3e86d34 0x7ffdc3e86d34
    // ++, --
    p++;
    q--;
    cout << p << " " << q << endl; // 0x7ffdc3e86d38 0x7ffdc3e86d30
    // +, -
    p = p - 1;
    q = q + 1;
    cout << p << " " << q << endl; // 0x7ffdc3e86d34 0x7ffdc3e86d34
    // +=
    p += 2;
    cout << p << endl; // 0x7ffd06befb1c
    return 0;
}
