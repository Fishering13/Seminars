#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int sum = 0;
    for (int i = 1; i <= 50; i++)
    {
        if (i % 5 == 0 || i % 7 == 0)
        {
            sum += i;
        }
    }
    cout << "Сумма чисел, делящихся на 5 или на 7: " << sum << '\n';
    return 0;
}
