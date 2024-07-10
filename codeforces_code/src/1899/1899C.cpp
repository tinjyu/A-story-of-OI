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
        long long int ans = -999999999999999;
        long long int pre = 0;
        for (int i = 1; i <= n; i++)
        {
            if (abs(a[i]) % 2 != abs(a[i - 1]) % 2)
                pre += a[i];
            else
                pre = a[i];
            ans = max(ans, pre);
            if (pre < 0)
                pre = 0;
        }
        cout << ans << endl;
    }
}