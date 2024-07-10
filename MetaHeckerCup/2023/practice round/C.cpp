#include <iostream>
#include <algorithm>
using namespace std;
long long int n, a[1000005];
int scan(int p, int q, long long int tar)
{
    while (p <= q)
    {
        if (a[p] + a[q] != tar)
            return 0;
        p++;
        q--;
    }
    return 1;
}
long long int check(long long int tar)
{
    int p = 1, q = n;
    long long int ans = 9999999999999;
    while (p <= q)
    {
        if (p == q)
        {
            if (tar - a[p] > 0)
                ans = tar - a[p];
            break;
        }
        if (a[p] + a[q] != tar)
        {
            if (scan(p + 1, q, tar) == 1)
            {
                if (tar - a[p] > 0)
                    ans = min(ans, tar - a[p]);
            }
            if (scan(p, q - 1, tar) == 1)
            {
                if (tar - a[q] > 0)
                    ans = min(ans, tar - a[q]);
            }
            break;
        }
        p++;
        q--;
    }
    return ans;
}
long long int solve()
{
    cin >> n;
    n = n * 2 - 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
        return 1;
    sort(a + 1, a + n + 1);
    long long int ans = 9999999999999;
    ans = min(ans, check(a[1] + a[n]));
    ans = min(ans, check(a[2] + a[n]));
    ans = min(ans, check(a[1] + a[n - 1]));
    if (ans == 9999999999999)
        return -1;
    return ans;
}
int main()
{
    freopen("two_apples_a_day_input.txt", "r", stdin);
    freopen("two_apples_a_day_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}