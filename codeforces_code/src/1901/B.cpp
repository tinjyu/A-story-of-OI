#include <iostream>
using namespace std;
long long int n, x, a[100005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> x;
        int flag = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = 0;
        a[n + 1] = x;
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, a[i + 1] - a[i]);
        }
        ans = max((a[n + 1] - a[n]) * 2, ans);
        cout << ans << endl;
    }
}