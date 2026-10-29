#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    double a[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Введите число " << i + 1 << ": ";
        cin >> a[i];
        if (a[i] > 15)
        {
            a[i] = 15;
        }
    }
    cout << "Полученные числа:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
