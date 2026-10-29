#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    cout << "Размеры всех типов данных в байтах:" << '\n';
    cout << "char:                    " << sizeof(char) << " байт" << '\n';
    cout << "char16_t:                " << sizeof(char16_t) << " байт" << '\n';
    cout << "char32_t:                " << sizeof(char32_t) << " байт" << '\n';
    cout << "wchar_t:                 " << sizeof(wchar_t) << " байт" << '\n';
    cout << "signed char:             " << sizeof(signed char) << " байт" << '\n';
    cout << "signed short int:        " << sizeof(signed short int) << " байт" << '\n';
    cout << "signed int:              " << sizeof(signed int) << " байт" << '\n';
    cout << "signed long int:         " << sizeof(signed long int) << " байт" << '\n';
    cout << "signed long long int:    " << sizeof(signed long long int) << " байт" << '\n';
    cout << "unsigned char:           " << sizeof(unsigned char) << " байт" << '\n';
    cout << "unsigned short int:      " << sizeof(unsigned short int) << " байт" << '\n';
    cout << "unsigned int:            " << sizeof(unsigned int) << " байт" << '\n';
    cout << "unsigned long int:       " << sizeof(unsigned long int) << " байт" << '\n';
    cout << "unsigned long long int:  " << sizeof(unsigned long long int) << " байт" << '\n';
    cout << "float:                   " << sizeof(float) << " байт" << '\n';
    cout << "double:                  " << sizeof(double) << " байт" << '\n';
    cout << "long double              " << sizeof(long double) << " байт" << '\n';
return 0;
}
