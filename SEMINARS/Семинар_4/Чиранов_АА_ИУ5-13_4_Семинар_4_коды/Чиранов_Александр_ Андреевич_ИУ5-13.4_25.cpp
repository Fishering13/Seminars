#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Введите число " << i + 1 << ": ";
        cin >> *(arr + i);
    }
    cout << "Массив: ";
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr + i) << ' ';
    }
    cout << '\n';
    return 0;
}
