#include <iostream>
using namespace std;
long long int n, a[200005], b[200005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        long long int ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        long long int mx = 0, mi = 1e15;
        for (int i = 1; i <= n; i++)
        {
            ans += abs(a[i] - b[i]);
            mx = max(mx, min(a[i], b[i]));
            mi = min(mi, max(a[i], b[i]));
        }
        cout << max((long long int)0, mx - mi) * 2 + ans << endl;
    }
}