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
            cin >> a[i];
        long long int cnt = 0;
        long long int ans = 0;
        long long int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                cnt1++;
                ans += cnt2;
            }
            if (a[i] == 2)
            {
                cnt2++;
                ans += cnt1;
            }
        }
        sort(a + 1, a + n + 1);
        a[n + 1] = -1;
        for (int i = 1; i <= n + 1; i++)
        {
            if (a[i] != a[i - 1])
            {
                ans += cnt * (cnt - 1) / 2;
                cnt = 0;
            }
            cnt++;
        }
        cout << ans << endl;
    }
}