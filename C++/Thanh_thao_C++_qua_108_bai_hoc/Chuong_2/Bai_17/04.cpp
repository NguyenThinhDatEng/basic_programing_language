#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n; // n is a 3 digit number
    cin >> n;
    int numberOfUnits = 0, res = 0;
    // first
    numberOfUnits = n % 10;
    res += numberOfUnits * 100;
    n /= 10;
    // second
    numberOfUnits = n % 10;
    res += numberOfUnits * 10;
    n /= 10;
    // third
    res += n;
    cout << res;
    return 0;
}