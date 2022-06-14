#include <iostream>
using namespace std;

int main()
{
    int *p;
    int var = 13;
    // &
    p = &var; // p is pointing to var's address
    delete p; // memory recovery
    return 0;
}