#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    cout << "Адреса через &arr[i]:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << &arr[i] << '\n';
    }
    cout << "Адреса через ptr + i:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << ptr + i << '\n';
    }
    return 0;
}
