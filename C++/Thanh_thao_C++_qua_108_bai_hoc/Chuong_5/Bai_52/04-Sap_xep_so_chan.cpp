#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // given variables
    int n; // number of elements
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // algo
    int b[n];         // contains the even elements of array a
    int quantity = 0; // number of even elements
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[quantity] = a[i];
            quantity++;
        }
    }

    if (quantity > 0)
    {
        // bubble sort
        int tmp;
        for (int i = 0; i < quantity; i++)
            for (int j = quantity - 1; j > i; j--)
                if (b[j] < b[j - 1])
                {
                    tmp = b[j];
                    b[j] = b[j - 1];
                    b[j - 1] = tmp;
                }
        // assign for array a
        for (int i = n - 1; i >= 0 && quantity > 0; i--)
        {
            if (a[i] % 2 == 0)
            {
                quantity--;
                a[i] = b[quantity];
            }
        }
    }
    // display
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}