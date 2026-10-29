#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int var = 42;
    cout << "Значение var: " << var << '\n';
    cout << "Адрес var (в шестнадцатиричном формате): " << &var << '\n';
    setlocale(LC_ALL, "Russian");
return 0;
}
