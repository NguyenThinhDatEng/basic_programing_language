#include <iostream>
#include <cstring> // strcpy(char * dest, const char * src)
                   // strncpy(char * dest, const char * src, int n)
using namespace std;

int main()
{
    const char src[18] = "I love my school!";
    char destination[2] = "";
    cout << "the length of source: " << strlen(src) << endl;
    cout << "the length of destination: " << strlen(destination) << endl;

    // NOT COPY
    cout << "-----strcpy-----" << endl; // delete the content of dest string
    strcpy(destination, src);           // cut n digits (n = the length of dest) from src then paste in dest
    puts(destination);
    puts(src);

    // COPY
    cout << "-----strncpy-----" << endl;
    // the length of source < n => add spaces for enough n digits
    strncpy(destination, src, 2); // do not remove the content of dest
    puts(destination);            // copy n digits from src then paste in dest
    puts(src);

    cout << endl;
    return 0;
}
