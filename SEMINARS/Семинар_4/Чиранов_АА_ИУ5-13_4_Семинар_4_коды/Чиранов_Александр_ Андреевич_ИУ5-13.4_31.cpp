#include <iostream>
#include <clocale>
#include <vector>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    v.push_back(7);
    cout << "После push_back: ";
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
    cout << "v.at(0) = " << v.at(0) << '\n';
    cout << "v.at(2) = " << v.at(2) << '\n';
    cout << "v.at(4) = " << v.at(4) << '\n';
    v.at(1) = 20;
    v.at(4) = 50;
    cout << "После изменения: ";
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
    v.pop_back();
    cout << "После pop_back: ";
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
