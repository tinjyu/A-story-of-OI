#include <iostream>
#include <algorithm>
using namespace std;
long long int n, q, d[1000005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> q;
        for (int i = 1; i <= q; i++)
            cin >> d[i];
        for (int i = 1; i < n; i++)
        {
            cout << i << " " << i + 1 << endl;
        }
        int pre = n - 1;
        for (int i = 1; i <= q; i++)
        {
            if (d[i] == pre)
            {
                cout << "-1 -1 -1" << endl;
                continue;
            }
            cout << n << " " << pre << " " << d[i] << endl;
            pre = d[i];
        }
    }
}