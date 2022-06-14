#include <iostream>

using namespace std;

int **allocateMemory(int m, int n);
void input(int **a, int m, int n);
void displayArr(int **a, int m, int n);
void show_principal_diagonal(int **a, int minOf_m_n);
void show_second_diagonal(int **a, int minOf_m_n);

int main(int argc, char const *argv[])
{
    int m, n; // number of rows and number of columns
    cin >> m >> n;
    int **a;
    a = allocateMemory(m, n);
    input(a, m, n);
    displayArr(a, m, n);
    cout << "Pricipal diagonal: " << endl;
    show_principal_diagonal(a, min(m, n));
    cout << "Second diagonal: " << endl;
    show_second_diagonal(a, min(m, n));
    return 0;
}

int **allocateMemory(int m, int n)
{
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
        *(a + i) = new int[n];
    return a;
}
void input(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> *(*(a + i) + j);
}
void displayArr(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << *(*(a + i) + j) << " ";
        cout << endl;
    }
}
void show_principal_diagonal(int **a, int minOf_m_n)
{
    for (int i = 0; i < minOf_m_n; i++)
        cout << a[i][i] << " ";
    cout << endl;
}
void show_second_diagonal(int **a, int minOf_m_n)
{
    for (int i = 0; i < minOf_m_n; i++)
        cout << a[i][minOf_m_n - 1 - i] << " ";
    cout << endl;
}