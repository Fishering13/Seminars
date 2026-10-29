#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    cout << "Введите целое число a: "; cin >> a;
    cout << "Введите целое число b: "; cin >> b;
    int mx = (a > b) ? a : b;
    cout << "Максимальное из двух чисел: " << mx;
return 0;
}
