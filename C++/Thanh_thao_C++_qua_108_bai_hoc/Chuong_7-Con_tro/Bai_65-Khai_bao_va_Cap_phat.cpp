#include <iostream>
using namespace std;

int main()
{
    // declare
    int *p;
    // allocation
    p = new int;
    // the address of the box which p is pointing to
    cout << p << endl;
    // the value of the variable which p is pointing to
    *p = 13;
    // delete pointer
    delete p; // memory recovery
    return 0;
}