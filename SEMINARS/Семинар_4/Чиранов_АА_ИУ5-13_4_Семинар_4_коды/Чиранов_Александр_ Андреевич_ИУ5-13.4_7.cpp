#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int sum = 0;
    for (int i = 10; i <= 99; i++)
    {
        sum += i;
    }
    cout << "Сумма всех двузначных чисел: " << sum << '\n';
    return 0;
}
