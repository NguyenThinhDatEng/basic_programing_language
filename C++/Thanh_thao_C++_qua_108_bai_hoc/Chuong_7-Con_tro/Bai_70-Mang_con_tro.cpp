#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // declare pointer array
    int *p[4];
    // assign the values to array
    for (int i = 0; i < 4; i++)
    {
        p[i] = new int;
        *p[i] = i;
    }
    // display
    for (int i = 0; i < 4; i++)
        cout << p[i] << "\t" << *p[i] << endl;
    return 0;
}