#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    double rate;
    cout << "Введите курс евро в рублях: ";
    cin >> rate;
    cout << "Евро -> рубли\n";
    for (int euro = 5; euro <= 25; euro++)
    {
        cout << euro << " евро = " << euro * rate << " руб.\n";
    }
    return 0;
}
