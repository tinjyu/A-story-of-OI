#include <iostream>
#include <algorithm>
using namespace std;
long long int n, a[1000005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        long long int ans = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (n % i != 0)
                continue;
            long long int mx = 0, mi = 1000000000000000000;
            for (int j = 1; j <= n; j += i)
            {
                long long int cnt = 0;
                for (int k = j; k < j + i; k++)
                    cnt += a[k];
                mx = max(mx, cnt);
                mi = min(mi, cnt);
            }
            ans = max(ans, mx - mi);
        }
        cout << ans << endl;
    }
}