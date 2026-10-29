#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Цикл for с индексом: ";
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << '\n';
    cout << "Цикл for с диапазоном: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << '\n';
    return 0;
}
