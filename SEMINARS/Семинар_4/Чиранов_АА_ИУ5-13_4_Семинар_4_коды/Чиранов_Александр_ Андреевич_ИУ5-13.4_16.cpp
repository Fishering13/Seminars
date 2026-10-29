#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int c[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Введите c" << i + 1 << ": ";
        cin >> c[i];
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += c[i] * c[i];
    }
    cout << "Сумма квадратов элементов: " << sum << '\n';
    return 0;
}
