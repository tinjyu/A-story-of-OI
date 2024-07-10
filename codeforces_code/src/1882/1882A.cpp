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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans + 1 == a[i])
                ans += 2;
            else
                ans++;
        }
        cout << ans << endl;
    }
}