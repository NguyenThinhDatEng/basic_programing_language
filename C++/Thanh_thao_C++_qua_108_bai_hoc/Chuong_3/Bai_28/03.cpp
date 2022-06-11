#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n; // n is a 2 digit number
    cin >> n;
    if (n / 10)
    {
        // tens
        switch (n / 10)
        {
        case 2:
            cout << "Hai";
            break;
        case 3:
            cout << "Ba";
            break;
        case 4:
            cout << "Bon";
            break;
        case 5:
            cout << "Nam";
            break;
        case 6:
            cout << "Sau";
            break;
        case 7:
            cout << "Bay";
            break;
        case 8:
            cout << "Tam";
            break;
        case 9:
            cout << "Chin";
            break;
        default:
            break;
        }

        if (n / 10 == 1)
        {
            cout << "Muoi ";
        }
        else
            cout << " muoi ";
        // units
        switch (n % 10)
        {
        case 1:
            cout << "mot";
            break;
        case 2:
            cout << "hai";
            break;
        case 3:
            cout << "ba";
            break;
        case 4:
            cout << "bon";
            break;
        case 5:
            cout << "lam";
            break;
        case 6:
            cout << "sau";
            break;
        case 7:
            cout << "bay";
            break;
        case 8:
            cout << "tam";
            break;
        case 9:
            cout << "chin";
            break;
        default:
            break;
        }
    }
    else // 0 < n <= 9
    {
        switch (n)
        {
        case 1:
            cout << "Mot";
            break;
        case 2:
            cout << "Hai";
            break;
        case 3:
            cout << "Ba";
            break;
        case 4:
            cout << "Bon";
            break;
        case 5:
            cout << "Nam";
            break;
        case 6:
            cout << "Sau";
            break;
        case 7:
            cout << "Bay";
            break;
        case 8:
            cout << "Tam";
            break;
        case 9:
            cout << "Chin";
            break;
        default:
            break;
        }
    }

    return 0;
}