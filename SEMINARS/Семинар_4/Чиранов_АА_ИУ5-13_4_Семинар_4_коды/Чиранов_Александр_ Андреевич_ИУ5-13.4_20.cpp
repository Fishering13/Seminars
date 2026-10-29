#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int test[2][3][2];
    int value = 1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                test[i][j][k] = value;
                value++;
            }
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << "test[" << i << "][" << j << "][" << k << "] = " << test[i][j][k] << '\n';
            }
        }
    }
    return 0;
}
