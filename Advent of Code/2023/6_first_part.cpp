#include <iostream>
using namespace std;

long long int t[10005], dis[10005];
int main()
{
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> dis[i];
    }
    long long int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= t[i]; j++)
        {
            int dist = (t[i] - j) * j;
            if (dist > dis[i])
                cnt++;
        }
        cout << cnt << endl;
        ans *= cnt;
    }
    cout << ans << endl;
}