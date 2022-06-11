#include <iostream>

using namespace std;

int main()
{
    // given variables
    int m, k, n; // arr1[m][k], arr2[k][n]
    cout << "m = ";
    cin >> m;
    cout << "k = ";
    cin >> k;
    cout << "n = ";
    cin >> n;

    int a[m][k], b[k][n]; // arrays
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cin >> a[i][j];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
    // execute
    int c[m][n]; // result
    int sum = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            for (int z = 0; z < k; z++)
                sum += a[i][z] * b[z][j];
            c[i][j] = sum;
        }
    // display
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}