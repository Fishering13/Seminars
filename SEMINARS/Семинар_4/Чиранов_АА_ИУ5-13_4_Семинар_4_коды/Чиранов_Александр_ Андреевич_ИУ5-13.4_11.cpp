#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество чисел N: ";
    cin >> n;
    int neg = 0, pos = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        double x;
        cout << "Введите число: ";
        cin >> x;
        if (x < 0)
        {
            neg++;
        }
        else if (x > 0)
        {
            pos++;
        }
        else
        {
            zero++;
        }
    }
    cout << "Отрицательных: " << neg << '\n';
    cout << "Положительных: " << pos << '\n';
    cout << "Нулей: " << zero << '\n';
    return 0;
}
