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
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Максимальный элемент: " << max << '\n';
    cout << "Минимальный элемент: " << min << '\n';
    return 0;
}
