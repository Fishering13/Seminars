#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int sum = 0;
    int i = 1;
    while (i <= 200)
    {
        sum += i;
        i += 2;
    }
    cout << "Сумма нечётных чисел от 1 до 200: " << sum << '\n';
    return 0;
}
