#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    char ch = 'A';
    char16_t u16 = u'B';
    char32_t u32 = U'C';
    wchar_t w = L'D';
    bool flag = true;
    cout << "Значение char:     " << ch << '\n';
    cout << "Значение char16_t: " << u16 << '\n';
    cout << "Значение char32_t: " << u32 << '\n';
    cout << "Значение wchar_t:  " << w << '\n';
    cout << "Значение bool:     " << boolalpha << flag;
return 0;
}
