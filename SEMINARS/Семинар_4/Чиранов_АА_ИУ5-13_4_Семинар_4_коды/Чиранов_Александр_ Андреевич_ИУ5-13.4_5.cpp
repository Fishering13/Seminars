#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    const double K = 2.5;
    cout << "Дюймы -> сантиметры\n";
    for (int inch = 1; inch <= 20; inch++)
    {
        cout << inch << " дюйм. = " << inch * K << " см\n";
    }
    return 0;
}
