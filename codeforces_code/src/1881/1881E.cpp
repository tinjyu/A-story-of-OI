#include <iostream>
#include <map>
using namespace std;
long long int a[1000005], n, dp[1000005];
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
        dp[n + 1] = 0;
        for (int i = n; i >= 1; i--)
        {
            dp[i] = dp[i + 1] + 1;
            if (i + a[i] <= n)
            {
                dp[i] = min(dp[i], dp[i + a[i] + 1]);
            }
        }
        cout << dp[1] << endl;
    }
}