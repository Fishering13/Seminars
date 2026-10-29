#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int i;
    double d;
    char c;

    cout << "Введите целое число: "; cin >> i;
    cout << "Введите дробное число: "; cin >> d;
    cout << "Введите символ: "; cin >> c;
    cout << '\n';

    int d_int = (int)d;
    int c_code = (int)c;

    cout << boolalpha;

    cout << "Исходное целое:            " << i << '\n';
    cout << "Исходное дробное:          " << d << '\n';
    cout << "Приведённое дробное:       " << d_int << '\n';
    cout << "Символ:                    " << c << '\n';
    cout << "Код символа:               " << c_code << '\n';
    cout << '\n';

    cout << "Сумма целого и приведённого дробного: " << i + d_int << '\n';
    cout << "Разность целого и кода символа:       " << i - c_code << '\n';
    cout << "Сравнение (i == d_int):               " << (i == d_int) << '\n';
    cout << "Логическое выражение (i > 10) && (c_code < 100): " << ((i > 10) && (c_code < 100)) << '\n';
    cout << '\n';

    cout << "Размер int:    " << sizeof(i) << " байт" << '\n';
    cout << "Размер double: " << sizeof(d) << " байт" << '\n';
    cout << "Размер char:   " << sizeof(c) << " байт" << '\n';
    cout << "Размер bool:   " << sizeof(bool) << " байт" << '\n';

return 0;
}
