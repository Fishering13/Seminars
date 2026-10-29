#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int a = 5, b = 4;
    double c = 5.0;
    char d = 'A';
    bool e = true;
    cout << "Размер int:    "  << sizeof(a)<< " байт\n";
    cout << "Размер double: "  << sizeof(c)<< " байт\n";
    cout << "Размер char:   "  << sizeof(d)<< " байт\n";
    cout << "Размер bool:   "  << sizeof(e)<< " байт\n";
    cout << "Размер выражения (a + b): " << sizeof(a + b) << " байт";
return 0;
}
