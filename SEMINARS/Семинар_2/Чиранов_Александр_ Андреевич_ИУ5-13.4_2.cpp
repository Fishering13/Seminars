#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    double d1 = 7.0, d2 = 2.0;
    int a1 = 7, a2 = 2;
    cout << "Результат деления вещественных чисел: " << d1 / d2 << '\n';
    cout << "Результат деления целочисленных чисел: " << a1 / a2 << '\n';
return 0;
}
