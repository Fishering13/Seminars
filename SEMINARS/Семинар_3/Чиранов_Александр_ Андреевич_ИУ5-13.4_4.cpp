#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

int count_divisions(int m, int n)
{
    int cnt = 0;
    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
        cnt++;
    }
    return cnt;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int table[11][11];
    int mn = 100, mx = 0;
    cout << "Число делений (строки - m, столбцы - n):\n";
    cout << "    ";
    for (int n = 1; n <= 10; n++)
        cout << setw(3) << n;
    cout << '\n';
    for (int m = 1; m <= 10; m++)
    {
        cout << setw(3) << m << ":";
        for (int n = 1; n <= 10; n++)
        {
            table[m][n] = count_divisions(m, n);
            cout << setw(3) << table[m][n];
            if (table[m][n] < mn)
                mn = table[m][n];
            if (table[m][n] > mx)
                mx = table[m][n];
        }
        cout << '\n';
    }
    int cnt_min = 0, cnt_max = 0;
    for (int m = 1; m <= 10; m++)
        for (int n = 1; n <= 10; n++)
        {
            if (table[m][n] == mn)
                cnt_min++;
            if (table[m][n] == mx)
                cnt_max++;
        }
    cout << "\nМинимум: " << mn << " деление, пар: " << cnt_min << '\n';
    cout << "Максимум: " << mx << " делений, пар: " << cnt_max << '\n';
    cout << "Пары с максимумом:";
    for (int m = 1; m <= 10; m++)
        for (int n = 1; n <= 10; n++)
            if (table[m][n] == mx)
                cout << " (" << m << ", " << n << ")";
    cout << '\n';
return 0;
}
