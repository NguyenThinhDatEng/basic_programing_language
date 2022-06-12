#include <iostream>
#include <math.h>
using namespace std;

int sumOfDivisors(int n)
{
    int sum = 0;
    int sqrtOf_n = sqrt(n);
    // calculate sum
    for (int i = 2; i <= sqrtOf_n; i++)
        if (n % i == 0)
            sum += i + n / i;
    // check: 2 divisors are the same
    if (sqrtOf_n * sqrtOf_n == n)
        sum -= sqrtOf_n;
    return sum;
}

void isAbundantNumber(int n) // /əˈbʌn.dənt/
{
    if (sumOfDivisors(n) > n)
        cout << n << " is an abundant number";
    else
        cout << n << " isn't an abundant number";
    cout << endl;
}

int main()
{
    int n;  // n is a positive integer
    cin >> n;
    isAbundantNumber(n);
    return 0;
}