#include <iostream>
using namespace std;
int n, a[100005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[i + 1])
                ans = max(ans, a[i]);
        }
        cout << ans << endl;
    }
}