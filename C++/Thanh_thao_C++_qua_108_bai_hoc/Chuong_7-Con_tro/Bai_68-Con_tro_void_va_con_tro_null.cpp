#include <iostream>
using namespace std;

int main()
{
    int *p; // p is a NULL pointer
    // void pointer
    void *q;
    int a = 1;
    float b = 2;
    char c = 'c';
    // void pointer can point to any data types
    q = &a;
    q = &b;
    q = &c;
    // must type casting in the calculation
    char d = *(char *)q + 1;
    cout << d << endl;
    *(int *)q = 6;
    cout << *(int *)q << endl;
    return 0;
}