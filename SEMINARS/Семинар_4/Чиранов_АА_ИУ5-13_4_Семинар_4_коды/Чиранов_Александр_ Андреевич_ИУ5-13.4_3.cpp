#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    cout << "Цикл while:\n";
    int i = 0;
    while (i <= 100)
    {
        cout << i << '\n';
        i += 2;
    }
    cout << "Цикл for:\n";
    for (int j = 0; j <= 100; j += 2)
    {
        cout << j << '\n';
    }
    return 0;
}
