#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    double pi = 3.14159;
    int pi_int = int(pi);
    int pi_int2 = (int)pi;
    cout << "Число Пи: " << pi << '\n';
    cout << "Первый вариант приведения: " << pi_int << '\n';
    cout << "Второй вариант приведения: " << pi_int2;
return 0;
}
