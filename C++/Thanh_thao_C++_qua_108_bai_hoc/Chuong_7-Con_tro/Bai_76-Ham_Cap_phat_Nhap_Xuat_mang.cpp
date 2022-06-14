#include <iostream>

using namespace std;

int *allocateMemory(int n);
void input(int *a, int n);
void display(int *a, int n);

int main(int argc, char const *argv[])
{
    int n; // number of elements
    cin >> n;
    int *a = allocateMemory(n);
    input(a, n);
    display(a, n);
    return 0;
}

int *allocateMemory(int n)
{
    return new int[n];
}

void input(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cin >> *(a + i);
}

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << *(a + i) << "\t";
    cout << endl;
}
