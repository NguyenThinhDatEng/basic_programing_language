#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // declare and init
    int *p;
    int a[] = {0, 1, 2, 3};
    // assign
    p = a;
    // display
    for (int i = 0; i < 4; i++)
        cout << *(p + i) << endl;
    return 0;
}