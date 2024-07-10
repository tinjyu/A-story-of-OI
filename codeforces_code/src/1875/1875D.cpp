#include <iostream>
#include <algorithm>
using namespace std;
long long int n, a[100005], cnt[1000005], dp[100004];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cnt[i] = 0;
            cin >> a[i];
            dp[i] = 0;
        }
        cnt[0] = 0;
        dp[0] = 0;
        sort(a + 1, a + n + 1);
        int p = -1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == p)
                cnt[p]++;
            else
            {
                if (a[i] != p + 1)
                    break;
                p++;
                cnt[p]++;
            }
        }
        for (int i = p; i >= 0; i--)
        {
            long long int sum = 0;
            dp[i] = 10000000000000;
            for (int j = i + 1; j <= p + 1; j++)
            {
                dp[i] = min(dp[i], dp[j] + (cnt[i] - 1) * j + i);
            }
        }
        cout << dp[0] << endl;
    }
}