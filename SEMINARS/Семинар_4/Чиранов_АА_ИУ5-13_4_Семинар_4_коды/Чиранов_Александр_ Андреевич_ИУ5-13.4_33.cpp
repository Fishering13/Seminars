#include <iostream>
#include <clocale>
#include <vector>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    vector<int> numbers = {7, 12, 3, 18, 5, 8, 21, 10};
    cout << "Исходный вектор: ";
    for (int x : numbers)
    {
        cout << x << ' ';
    }
    cout << '\n';
    int sum = 0;
    int max = numbers[0], min = numbers[0];
    for (int x : numbers)
    {
        sum += x;
        if (x > max)
        {
            max = x;
        }
        if (x < min)
        {
            min = x;
        }
    }
    cout << "Сумма элементов: " << sum << '\n';
    cout << "Среднее арифметическое: " << (double)sum / numbers.size() << '\n';
    cout << "Максимальный элемент: " << max << '\n';
    cout << "Минимальный элемент: " << min << '\n';
    int i = 0;
    while (i < (int)numbers.size())
    {
        if (numbers[i] % 2 == 0)
        {
            numbers.erase(numbers.begin() + i);
        }
        else
        {
            i++;
        }
    }
    cout << "Вектор без чётных элементов: ";
    for (int x : numbers)
    {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
