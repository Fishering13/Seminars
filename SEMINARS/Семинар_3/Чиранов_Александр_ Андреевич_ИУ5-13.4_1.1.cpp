#include <iostream>
#include <clocale>
using namespace std;

int gcd_euclid(int m, int n)
{
    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int m, n;
    cout << "Введите m: "; cin >> m;
    cout << "Введите n: "; cin >> n;
    cout << "НОД(" << m << ", " << n << ") = " << gcd_euclid(m, n) << '\n';
return 0;
}

