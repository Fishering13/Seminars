#include <iostream>
#include <clocale>
#include <vector>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int arr[3] = {1, 2, 3};
    vector<int> v = {1, 2, 3};
    cout << "Размер массива (фиксирован): " << sizeof(arr) / sizeof(arr[0]) << '\n';
    cout << "Размер вектора до добавления: " << v.size() << '\n';
    v.push_back(4);
    v.push_back(5);
    cout << "Размер вектора после push_back: " << v.size() << '\n';
    cout << "Ёмкость вектора: " << v.capacity() << '\n';
    return 0;
}
