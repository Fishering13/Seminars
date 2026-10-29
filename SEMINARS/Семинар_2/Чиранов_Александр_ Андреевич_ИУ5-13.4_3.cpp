#include <iostream>
#include <clocale>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int x = 10;
    x += 5;
    cout << "x = x + 5: " << x << '\n';
    x -= 3;
    cout << "x = x - 3: " << x << '\n';
    x *= 2;
    cout << "x = x * 2: " << x << '\n';
    x /= 4;
    cout << "x = x / 4: " << x << '\n';
    x %= 3;
    cout << "x = x % 3: " << x << '\n';
return 0;
}
