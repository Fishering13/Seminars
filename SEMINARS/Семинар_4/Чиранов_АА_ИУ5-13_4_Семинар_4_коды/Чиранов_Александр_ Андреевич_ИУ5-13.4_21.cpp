#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int var1 = 3, var2 = 24, var3 = 17;
    cout << "Адрес var1: " << &var1 << '\n';
    cout << "Адрес var2: " << &var2 << '\n';
    cout << "Адрес var3: " << &var3 << '\n';
    return 0;
}
