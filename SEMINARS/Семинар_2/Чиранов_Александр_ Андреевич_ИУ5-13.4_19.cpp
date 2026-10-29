#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    float f = 1.0f / 3.0f;
    double d = 1.0 / 3.0;
    long double ld = 1.0L / 3.0L;

    cout << "Значение 1.0 / 3.0 с точностью 6 (по умолчанию):\n";
    cout << "float:       " << f  << '\n';
    cout << "double:      " << d  << '\n';
    cout << "long double: " << ld << '\n';
    cout << '\n';

    cout.precision(15);
    cout << fixed;
    cout << "Значение 1.0 / 3.0 с точностью 15 (fixed):\n";
    cout << "float:       " << f  << '\n';
    cout << "double:      " << d  << '\n';
    cout << "long double: " << ld << '\n';
    cout << '\n';

    cout.precision(19);
    cout << "Значение 1.0 / 3.0 с точностью 19 (fixed):\n";
    cout << "float:       " << f  << '\n';
    cout << "double:      " << d  << '\n';
    cout << "long double: " << ld << '\n';

return 0;
}
