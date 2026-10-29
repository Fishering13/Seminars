#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int a = 2;
    int b = 3;
    int c = 4;
    int result = a + b * c - a / b % c;
    cout << "Результат арифметического выражения: " << result;
    setlocale(LC_ALL, "Russian");
return 0;
}

