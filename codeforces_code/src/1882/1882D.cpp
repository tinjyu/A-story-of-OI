#include <iostream>
using namespace std;
long long int n, a[1000005], cnt[1000005], tempans = 0, anslist[1000005];
long long int mp[1000005][2], road[1000005];
void dfs(int x, int fa)
{
    int g = road[x];
    cnt[x] = 1;
    while (g != -1)
    {
        int now = mp[g][0];
        if (now != fa)
        {
            dfs(now, x);
            cnt[x] += cnt[now];
            tempans += cnt[now] * (a[x] ^ a[now]);
        }
        g = mp[g][1];
    }
    return;
}

void solve(int x, int fa, long long int ans)
{
    int g = road[x];
    while (g != -1)
    {
        int now = mp[g][0];
        if (now != fa)
        {
            anslist[now] = ans + (n - 2 * cnt[now]) * (a[x] ^ a[now]);
            solve(now, x, anslist[now]);
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
        tempans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            anslist[i] = 0;
            cin >> a[i];
            road[i] = -1;
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
        dfs(1, -1);
        anslist[1] = tempans;
        solve(1, -1, tempans);
        for (int i = 1; i <= n; i++)
            cout << anslist[i] << " ";
        cout << endl;
    }
}