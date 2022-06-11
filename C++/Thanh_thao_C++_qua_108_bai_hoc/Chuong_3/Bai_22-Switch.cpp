#include <iostream>

using namespace std;

int main()
{
    int month;
    cin >> month;
    // display the month in letters
    switch (month)
    {
    case 1:
        cout << "Janunary";
        break;
    case 2:
        cout << "Febunary";
        break;
    case 3:
        cout << "March";
        break;
    case 4:
        cout << "April";
        break;
    case 5:
        cout << "May";
        break;
    case 6:
        cout << "June";
        break;
    case 7:
        cout << "July";
        break;
    case 8:
        cout << "August";
        break;
    case 9:
        cout << "September";
        break;
    case 10:
        cout << "Octorber";
        break;
    case 11:
        cout << "November";
        break;
    case 12:
        cout << "December";
        break;
    default:
        cout << "Month starts from 1 to 12";
        break;
    }
    return 0;
}