#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int x = 10;
    char c = 'A';
    int* pi = &x;
    char* pc = &c;
    cout << "Адрес pi: " << pi << '\n';
    cout << "Адрес pi + 1: " << pi + 1 << '\n';
    cout << "Адрес pc: " << (void*)pc << '\n';
    cout << "Адрес pc + 1: " << (void*)(pc + 1) << '\n';
    cout << "sizeof(int) = " << sizeof(int) << '\n';
    cout << "sizeof(char) = " << sizeof(char) << '\n';
    return 0;
}
