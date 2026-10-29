#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int var = 5;
    int* point_var = &var;      // исправлено: указателю присваивается адрес
    cout << "var = " << var << ", *point_var = " << *point_var << '\n';
    point_var = &var;           // верно: указателю присваивается адрес var
    *point_var = var;           // верно: по адресу записывается значение var
    cout << "var = " << var << ", *point_var = " << *point_var << '\n';
    return 0;
}
