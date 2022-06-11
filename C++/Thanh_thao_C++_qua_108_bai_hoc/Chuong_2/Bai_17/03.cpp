#include <iostream>
#include <math.h> // sqrt(double)
using namespace std;

int main(int argc, char const *argv[])
{
    double xA, yA, xB, yB; // point coordinates
    cin >> xA >> yA >> xB >> yB;
    cout << sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
    return 0;
}