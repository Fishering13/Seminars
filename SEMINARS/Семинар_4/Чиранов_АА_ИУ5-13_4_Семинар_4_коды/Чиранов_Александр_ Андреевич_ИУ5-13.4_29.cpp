#include <iostream>
#include <clocale>
#include <vector>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 {6, 7, 8, 9, 10};
    vector<int> v3(5, 12);
    cout << "v1: ";
    for (int x : v1)
    {
        cout << x << ' ';
    }
    cout << '\n';
    cout << "v2: ";
    for (int x : v2)
    {
        cout << x << ' ';
    }
    cout << '\n';
    cout << "v3: ";
    for (int x : v3)
    {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
