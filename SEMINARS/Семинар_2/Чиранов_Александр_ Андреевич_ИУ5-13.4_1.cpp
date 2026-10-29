#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int a = 17, b = 5;
    cout << "Сумма a и b: " << a + b << '\n';
    cout << "Разность a и b: " << a - b << '\n';
    cout << "Произведение a и b: " << a * b  << '\n';
    cout << "Целочисленное частное a и b: " << a / b << '\n';
    cout << "Остаток от деления a на b: " << a % b << '\n';
return 0;
}
