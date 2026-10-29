#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int var = 5;
    int* point_var = &var;
    cout << "var до изменения: " << var << '\n';
    *point_var = 16;
    cout << "var после *point_var = 16: " << var << '\n';
    cout << "*point_var: " << *point_var << '\n';
    return 0;
}
