#include <iostream>
#include <clocale>
#include <vector>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    vector<int> v = {2, 3, 5, 7};
    cout << "Размер (size): " << v.size() << '\n';
    cout << "Первый элемент (front): " << v.front() << '\n';
    cout << "Последний элемент (back): " << v.back() << '\n';
    cout << "Вектор пуст (empty): " << v.empty() << '\n';
    cout << "Ёмкость (capacity): " << v.capacity() << '\n';
    return 0;
}
