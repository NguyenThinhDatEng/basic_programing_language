#include <iostream>
#include <math.h> // pow(double, double)
using namespace std;

int main(int argc, char const *argv[])
{
    int n; // exponent
    double x;
    cin >> n >> x;
    double a = x * x + x + 1;
    cout << pow(a, n) + pow(a - 2 * x, n);
    return 0;
}