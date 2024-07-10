#include <iostream>
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
        {
            cin >> a[i];
        }
        long long int ans = 0, mx = 1e15;
        for (int i = n; i >= 1; i--)
        {
            if (a[i] <= mx)
            {
                mx = a[i];
                continue;
            }
            long long int temp = a[i] / mx + (a[i] % mx != 0);
            ans += temp - 1;
            mx = a[i] / temp;
        }
        cout << ans << endl;
    }
}