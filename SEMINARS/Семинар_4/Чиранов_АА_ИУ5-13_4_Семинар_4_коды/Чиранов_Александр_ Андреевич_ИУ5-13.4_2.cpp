#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    cout << "Цикл while:\n";
    int i = 11;
    while (i <= 33)
    {
        cout << i << '\n';
        i++;
    }
    cout << "Цикл for:\n";
    for (int j = 11; j <= 33; j++)
    {
        cout << j << '\n';
    }
    return 0;
}
