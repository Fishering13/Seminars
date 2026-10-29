#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    const int MAX_N = 100;
    int arr[MAX_N];
    int n;
    cout << "Введите количество элементов (до " << MAX_N << "): ";
    cin >> n;
    if (n < 1 || n > MAX_N)
    {
        cout << "Недопустимое количество элементов\n";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    cout << "Массив: ";
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
        sum += arr[i];
    }
    cout << '\n';
    cout << "Сумма элементов: " << sum << '\n';
    cout << "Среднее арифметическое: " << (double)sum / n << '\n';
    return 0;
}
