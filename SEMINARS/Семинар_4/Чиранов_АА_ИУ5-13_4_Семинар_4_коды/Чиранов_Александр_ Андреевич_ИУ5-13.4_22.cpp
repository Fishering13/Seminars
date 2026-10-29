#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int var = 5;
    int* point_var = &var;
    cout << "Значение var: " << var << '\n';
    cout << "Адрес var (&var): " << &var << '\n';
    cout << "Значение указателя point_var: " << point_var << '\n';
    cout << "Значение по адресу (*point_var): " << *point_var << '\n';
    return 0;
}
