#include <iostream>

using namespace std;

void swap(int *&pa, int *&pb);

int main()
{
    int a = 1, b = 2;
    swap(a, b); // pointer pa is pointing to a  
    cout << a << "\t" << b << endl;
    return 0;
}

void swap(int *&pa, int *&pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}