#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int c[7];
    int a, b;
    for (int i = 0; i < 7; i++)
    {
        cout << "Введите c" << i + 1 << ": ";
        cin >> c[i];
    }
    cout << "Введите A: ";
    cin >> a;
    cout << "Введите B: ";
    cin >> b;
    int count = 0;
    for (int i = 0; i < 7; i++)
    {
        if (c[i] >= a && c[i] <= b)
        {
            count++;
        }
    }
    cout << "Количество элементов в промежутке [" << a << ", " << b << "]: " << count << '\n';
    return 0;
}
