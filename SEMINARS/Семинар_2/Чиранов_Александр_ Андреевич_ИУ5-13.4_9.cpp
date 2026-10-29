#include <iostream>
#include <clocale>
#include <string>
using namespace std;
int main ()
{
    setlocale(LC_ALL, "Russian");
    int age = 20;
    string status = (age > 18) ? "Совершеннолетний" : "Несовершеннолетний";
    cout << status;
return 0;
}
