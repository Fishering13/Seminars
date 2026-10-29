#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    b = a ^ b;
    a = b ^ a;
    b = b ^ a;
    cout << "After swap: a = " << a << ", b = " << b;
return 0;
}
