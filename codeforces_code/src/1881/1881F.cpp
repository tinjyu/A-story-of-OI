#include <iostream>
using namespace std;
long long int n, k, a[1000005];
long long int mp[1000005][2], road[1000005];
long long int dis[1000005];
void dfs(int x, int fa)
{
    long long int g = road[x];
    while (g != -1)
    {
        long long int now = mp[g][0];
        if (now != fa)
        {
            dis[now] = dis[x] + 1;
            dfs(now, x);
        }
        g = mp[g][1];
    }
    return;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            dis[i] = 0;
            road[i] = -1;
        }
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            mp[i * 2][0] = v;
            mp[i * 2][1] = road[u];
            road[u] = i * 2;
            mp[i * 2 + 1][0] = u;
            mp[i * 2 + 1][1] = road[v];
            road[v] = i * 2 + 1;
        }
        dfs(a[1], -1);

        long long int p = 0, mx = 0;
        for (int i = 1; i <= k; i++)
        {
            if (dis[a[i]] >= mx)
            {
                mx = dis[a[i]];
                p = a[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            dis[i] = 0;
        }
        dfs(p, -1);
        mx = 0;
        for (int i = 1; i <= k; i++)
        {
            mx = max(mx, dis[a[i]]);
        }
        cout << mx / 2 + mx % 2 << endl;
    }
}