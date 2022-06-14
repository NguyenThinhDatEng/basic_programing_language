#include <iostream>
using namespace std;

void test1(int a)
{
    a *= 2;
}

void test2(int &a)
{
    a *= 2;
}

int main()
{
    int b = 6;
    test1(b);
    cout << b << endl;
    test2(b);
    cout << b << endl;
    return 0;
}