#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    int c = (a = 5, b = 7, a + b);
    cout << "c = " << c << '\n';
    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
    /*ќператор зап€та€ , в C++ позвол€ет объединить несколько выражений в одно.
    √лавна€ особенность: выражени€ выполн€ютс€ слева направо, но результатом
    всего выражени€ становитс€ результат последнего выражени€. */
return 0;
}

