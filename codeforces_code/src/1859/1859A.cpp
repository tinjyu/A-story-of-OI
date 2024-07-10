#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1000005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        if (a[1] == a[n])
        {
            cout << "-1" << endl;
            continue;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[n])
            {
                cnt = i - 1;
                break;
            }
        }
        cout << cnt << " " << n - cnt << endl;
        for (int i = 1; i <= cnt; i++)
            cout << a[i] << " ";
        cout << endl;
        for (int i = cnt + 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}