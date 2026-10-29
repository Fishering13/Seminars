#include <iostream>
#include <clocale>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <vector>
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

int gcd_school(int m, int n)
{
    vector<int> a = factorize(m);
    vector<int> b = factorize(n);
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

double measure(int (*f)(int, int), int m, int n, int calls)
{
    const int RUNS = 10;
    double total = 0.0;
    for (int r = 0; r < RUNS; ++r)
    {
        volatile int vm = m, vn = n;
        volatile int result = 0;
        auto start = chrono::steady_clock::now();
        for (int i = 0; i < calls; ++i)
            result = f(vm, vn);
        auto end = chrono::steady_clock::now();
        total += chrono::duration<double, milli>(end - start).count();
    }
    return total / RUNS;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int tests[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << fixed << setprecision(6);
    for (int i = 0; i < 3; i++)
    {
        int m = tests[i][0], n = tests[i][1], calls = tests[i][2];
        cout << "m = " << m << ", n = " << n << ", НОД = " << gcd_euclid(m, n)
             << " (вызовов за прогон: " << calls << ")\n";
        cout << "Евклид:   " << measure(gcd_euclid, m, n, calls) << " мс\n";
        cout << "Перебор:  " << measure(gcd_brute, m, n, calls) << " мс\n";
        cout << "Школьный: " << measure(gcd_school, m, n, calls) << " мс\n";
        cout << '\n';
    }
return 0;
}
