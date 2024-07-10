#include <iostream>
using namespace std;
long long int n, a[100005], k;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        a[n + 1] = a[n] - 1;
        long long int ans = 0;
        long long int sum = 0;
        for (long long int i = 1; i <= n; i++)
        {
            sum = 0;
            long long int mx = -1;
            for (long long int j = i; j <= n; j++)
            {
                mx = max(mx - 1, a[j]);
                sum += a[j];
                long long int l = min(a[j], a[j + 1] + 1), r = max(a[j], a[j + 1] + 1);
                l = max(mx, l);
                while (l <= r)
                {
                    long long int mid = (l + r) / 2;
                    if ((mid * 2 + j - i) * (j - i + 1) / 2 - sum <= k)
                    {
                        ans = max(ans, mid + j - i);
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
            }
        }
        cout << ans << endl;
    }
}