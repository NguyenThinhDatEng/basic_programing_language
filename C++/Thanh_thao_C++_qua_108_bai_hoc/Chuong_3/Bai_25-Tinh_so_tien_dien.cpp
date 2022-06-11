#include <iostream>

using namespace std;

int main()
{
    int electricNumber = 0;
    cin >> electricNumber;
    int electricMoney = 0;
    const int p1 = 1100, p2 = 900, p3 = 700, p4 = 600;  // constant

    if (electricNumber > 200)
        electricMoney += p1 * (electricNumber - 200) + 50 * (p2 + p3) + 100 * p4;
    else if (electricNumber > 150)
        electricMoney += p2 * (electricNumber - 150) + 50 * p3 + 100 * p4;
    else if (electricNumber > 100)
        electricMoney += p3 * (electricNumber - 100) + 100 * p4;
    else
        electricMoney += p4 * electricNumber;

    cout << electricMoney;
    return 0;
}