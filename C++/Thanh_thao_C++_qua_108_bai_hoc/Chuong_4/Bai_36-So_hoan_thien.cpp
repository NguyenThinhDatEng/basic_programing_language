#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n; // is a positive integer number
    cin >> n;
    // initialize variables
    int sqrtOf_n = sqrt(n);
    int sumOfDigits = 1;
    // algo
    for (int i = 2; i <= sqrtOf_n; i++)
    {
        if (n % i == 0)
            if (n / i != i)
                sumOfDigits += i + n / i;
            else
                sumOfDigits += i;
    }
    // display
    if (sumOfDigits == n)
        cout << n << " is a perfect number";
    else
        cout << n << " isn't a perfect number";
    return 0;
}