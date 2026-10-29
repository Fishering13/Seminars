#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    cout << "Цикл while:\n";
    int i = 1;
    while (i <= 100)
    {
        cout << i << '\n';
        i++;
    }
    cout << "Цикл for:\n";
    for (int j = 1; j <= 100; j++)
    {
        cout << j << '\n';
    }
    return 0;
}
