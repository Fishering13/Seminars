#include <iostream>
#include <clocale>
#include <vector>
using namespace std;

vector<int> factorize(int x)
{
    vector<int> f;
    for (long long p = 2; p * p <= x; p++)
    {
        while (x % p == 0)
        {
            f.push_back(p);
            x /= p;
        }
    }
    if (x > 1)
        f.push_back(x);
    return f;
}

int gcd_from_factors(const vector<int>& a, const vector<int>& b)
{
    int res = 1;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            res *= a[i];
            i++;
            j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
    return res;
}

void print_factors(int x, const vector<int>& f)
{
    cout << x << " = ";
    for (size_t i = 0; i < f.size(); i++)
    {
        if (i > 0)
            cout << " * ";
        cout << f[i];
    }
    cout << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int m, n;
    cout << "Введите m: "; cin >> m;
    cout << "Введите n: "; cin >> n;
    vector<int> a = factorize(m);
    vector<int> b = factorize(n);
    print_factors(m, a);
    print_factors(n, b);
    cout << "НОД(" << m << ", " << n << ") = " << gcd_from_factors(a, b) << '\n';
return 0;
}
