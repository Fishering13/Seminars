#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    const int MAX_N = 10;
    int a[MAX_N][MAX_N];
    int rows, cols;
    cout << "Введите количество строк и столбцов (до " << MAX_N << "): ";
    cin >> rows >> cols;
    if (rows < 1 || rows > MAX_N || cols < 1 || cols > MAX_N)
    {
        cout << "Недопустимые размеры\n";
        return 1;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    cout << "Массив:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
