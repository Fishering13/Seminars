#include <iostream>
#include <climits>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    signed char sc = SCHAR_MAX;
    short s  = SHRT_MAX;
    int i  = INT_MAX;
    long l  = LONG_MAX;
    long long ll = LLONG_MAX;

    unsigned char uc = UCHAR_MAX;
    unsigned short us = USHRT_MAX;
    unsigned int ui = UINT_MAX;
    unsigned long ul = ULONG_MAX;
    unsigned long long ull = ULLONG_MAX;

    cout << "Знаковые типы:\n";
    cout << "signed char:  " << (int)sc << '\n';
    cout << "short:        " << s  << '\n';
    cout << "int:          " << i  << '\n';
    cout << "long:         " << l  << '\n';
    cout << "long long:    " << ll << '\n';
    cout << '\n';
    cout << "Беззнаковые типы:\n";
    cout << "unsigned char:      " << (int)uc << '\n';
    cout << "unsigned short:     " << us  << '\n';
    cout << "unsigned int:       " << ui  << '\n';
    cout << "unsigned long:      " << ul  << '\n';
    cout << "unsigned long long: " << ull << '\n';
return 0;
}
