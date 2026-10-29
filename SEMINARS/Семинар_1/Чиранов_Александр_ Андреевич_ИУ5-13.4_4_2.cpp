#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int key = rand() % 100 + 1;
    vector <int> a;

    for (int i = 1; i <= 100; i++)
        a.push_back(i);
    int l = 1, r = 100;
    while (l <= r)
    {
        int m = (l + r) / 2;
        cout << a[m] << '\n';
        if (a[m] == key)
        {
            cout << "CONGRATULATIONS!";
            break;
        }
        if (a[m] < key)
        {
            cout << "more" << '\n';
            l = m + 1;
        }
        if (a[m] > key)
        {
            cout << "less" << '\n';
            r = m - 1;
        }
    }
return 0;
}
