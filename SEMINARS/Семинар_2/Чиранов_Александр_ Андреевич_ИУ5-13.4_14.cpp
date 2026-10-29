#include <iostream>
#include <clocale>
using namespace std;

int main ()
{
    setlocale(LC_ALL, "Russian");
    float f = 9.99;
    int f1 = int(f);
    char f2 = char(f1);
    cout << "Значение float: " << f << '\n';
    cout << "Значение int:   " << f1 << '\n';
    cout << "Значение char:  " << f2 << " код (" << int(f2) << ")" << '\n';
return 0;
}
