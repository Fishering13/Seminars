#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    const int MAX_N = 10;
    int a[MAX_N][MAX_N], b[MAX_N][MAX_N], sum[MAX_N][MAX_N];
    int r, c;
    cout << "Введите количество строк r и столбцов c (до " << MAX_N << "): ";
    cin >> r >> c;
    if (r < 1 || r > MAX_N || c < 1 || c > MAX_N)
    {
        cout << "Недопустимые размеры\n";
        return 1;
    }
    cout << "Введите элементы матрицы A:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Введите элементы матрицы B:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> b[i][j];
        }
    }
    cout << "Сумма матриц:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            cout << sum[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
