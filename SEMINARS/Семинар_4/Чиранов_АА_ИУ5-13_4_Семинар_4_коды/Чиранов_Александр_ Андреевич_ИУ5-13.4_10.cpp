#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    cout << "Числа, которые делятся на 3, но не делятся на 5:\n";
    for (int i = 20; i <= 50; i++)
    {
        if (i % 3 == 0 && i % 5 != 0)
        {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}
