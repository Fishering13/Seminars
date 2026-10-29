#include <iostream>
#include <clocale>
#include <chrono>
#include <iomanip>
using namespace std;

int euclid_steps(int m, int n, bool show)
{
    int cnt = 0;
    while (n != 0)
    {
        int r = m % n;
        cnt++;
        if (show)
            cout << "Шаг " << cnt << ": " << m << " % " << n << " = " << r << '\n';
        m = n;
        n = r;
    }
    if (show)
        cout << "НОД = " << m << '\n';
    return cnt;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "m = 24, n = 60 (первое число меньше):\n";
    int c1 = euclid_steps(24, 60, true);
    cout << "Делений: " << c1 << "\n\n";
    cout << "m = 60, n = 24 (первое число больше):\n";
    int c2 = euclid_steps(60, 24, true);
    cout << "Делений: " << c2 << "\n\n";

    int pairs[3][2] = {{5, 8}, {17, 40}, {123, 1000}};
    cout << "Сравнение числа делений:\n";
    for (int i = 0; i < 3; i++)
    {
        int m = pairs[i][0], n = pairs[i][1];
        cout << "(" << m << ", " << n << "): " << euclid_steps(m, n, false)
             << ", (" << n << ", " << m << "): " << euclid_steps(n, m, false) << '\n';
    }

    int fa = 1134903170, fb = 1836311903;
    const int RUNS = 10, CALLS = 100000;
    double total = 0.0;
    for (int r = 0; r < RUNS; ++r)
    {
        volatile int vm = fa, vn = fb;
        volatile int result = 0;
        auto start = chrono::steady_clock::now();
        for (int i = 0; i < CALLS; ++i)
            result = euclid_steps(vm, vn, false);
        auto end = chrono::steady_clock::now();
        total += chrono::duration<double, milli>(end - start).count();
    }
    cout << "\nХудший случай: m = " << fa << ", n = " << fb << '\n';
    cout << "Делений: " << euclid_steps(fa, fb, false) << '\n';
    cout << fixed << setprecision(4);
    cout << "Среднее время " << CALLS << " вызовов: " << total / RUNS << " мс\n";
return 0;
}

