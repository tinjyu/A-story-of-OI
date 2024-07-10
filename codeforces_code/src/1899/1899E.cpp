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
        long long int mi = 10000000000000000;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mi = min(mi, a[i]);
        }
        long long int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == mi)
            {
                ans = i - 1;
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] < a[j - 1])
                        ans = -1;
                }
                break;
            }
        }
        cout << ans << endl;
    }
}