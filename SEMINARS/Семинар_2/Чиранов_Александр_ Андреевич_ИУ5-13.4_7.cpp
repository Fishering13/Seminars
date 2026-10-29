#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    int a = 5, b = 10, c = 15;
    if ((a < b) && (b < c))
        cout << "true" << '\n';
    else
        cout << "false" << '\n';

    if ((a > b) || (b < c))
        cout << "true" << '\n';
    else
        cout << "false" << '\n';

    if (!((a + b) == c))
        cout << "true" << '\n';
    else
        cout << "false" << '\n';

    if ((a == 5) && (b != 10) || (c == 15))
        cout << "true" << '\n';
    else
        cout << "false" << '\n';
return 0;
}
