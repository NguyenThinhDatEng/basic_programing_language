#include <iostream>
#include <math.h>

#define n 1e6

using namespace std;

// the integral of f(x) on [a, b] is h * s
// h = (b - a) / n;
// s = the sum of f(a + i * h) (1 <= i <= n)
double integral(int start, int end);
void input(int &start, int &end);

int main(int argc, char const *argv[])
{
    int start, end;
    input(start, end);
    cout << integral(start, end);
    return 0;
}

double integral(int start, int end)
{
    double h = 1.0 * (end - start) / n;
    double x, s = 0;

    for (int i = 0; i < n; i++)
    {
        x = start + i * h;
        s += (exp(x) - 2 * sin(x * x)) / (1 + pow(x, 4)); // 2.12289
    }
    return h * s;
}

void input(int &start, int &end)
{
    cout << "start: ";
    cin >> start;
    cout << "end: ";
    cin >> end;
}