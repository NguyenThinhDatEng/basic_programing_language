#include <iostream>
using namespace std;

void test(int a, int b = 4)
{
    cout << a + b << endl;
}

int main()
{
    test(6);
    test(6, 14);
    return 0;
}