#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int sum1 = 0;
    int i = 1;
    while (i <= 100)
    {
        sum1 += i;
        i++;
    }
    cout << "Сумма чисел от 1 до 100 (while): " << sum1 << '\n';
    int sum2 = 0;
    for (int j = 1; j <= 100; j++)
    {
        sum2 += j;
    }
    cout << "Сумма чисел от 1 до 100 (for): " << sum2 << '\n';
    return 0;
}
