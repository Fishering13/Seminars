#include <iostream>
#include <clocale>
#include <algorithm>
using namespace std;

int gcd_brute(int m, int n)
{
    if (m == 0 || n == 0)
        return m + n;
    int t = min(m, n);
    while (t > 0)
    {
        if (m % t == 0 && n % t == 0)
            return t;
        t--;
    }
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int m, n;
    cout << "Введите m: "; cin >> m;
    cout << "Введите n: "; cin >> n;
    cout << "НОД(" << m << ", " << n << ") = " << gcd_brute(m, n) << '\n';
return 0;
}
