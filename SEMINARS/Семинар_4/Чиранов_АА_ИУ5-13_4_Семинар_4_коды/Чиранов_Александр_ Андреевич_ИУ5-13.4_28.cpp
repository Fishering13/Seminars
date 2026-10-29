#include <iostream>
#include <clocale>
#include <vector>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    cout << "Элементы вектора: ";
    for (int i = 0; i < (int)num.size(); i++)
    {
        cout << num[i] << ' ';
    }
    cout << '\n';
    cout << "Размер вектора: " << num.size() << '\n';
return 0;
}
