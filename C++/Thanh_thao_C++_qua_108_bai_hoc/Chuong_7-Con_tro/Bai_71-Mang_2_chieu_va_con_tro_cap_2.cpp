#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // the number of rows are 4
    int **p = new int *[4];
    // the number of columns are 2
    for (int i =  0; i < 4; i++)
        *(p + i) = new int[2];
    // assign the values to array
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            *(*(p + i) + j) = i + j;
    // display
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << *(*(p + i) + j) << "\t";
        cout << endl;
    }
    return 0;
}