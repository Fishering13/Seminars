#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int a = 8 , b = 12, c = 20;
    if (a < b)
        cout << "True" << '\n';
    else
        cout << "False" << '\n';

    if (a == c)
        cout << "True" << '\n';
    else
        cout << "False" << '\n';

    if (b * 2 >= c)
        cout << "True" << '\n';
    else
        cout << "False" << '\n';

    if (c - a != b)
        cout << "True" << '\n';
    else
        cout << "False" << '\n';

return 0;
}
