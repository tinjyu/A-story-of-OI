#include <iostream>
#include <algorithm>
using namespace std;
long long int n, q;
long long int road[1000005], mp[1000005][2];
long long int in[1000005], out[1000005], ans[1000005];
long long int dft[1000005], pos[1000005], p[1000005];
long long int tree[1000005];
long long int cnt = 0;
struct Node
{
    int x;
    int l;
    int r;
    int id;
};
bool operator<(Node a, Node b)
{
    return a.x <= b.x;
}
pair<int, Node> a[1000005];
void dfs(int x, int fa)
{
    cnt++;
    in[x] = cnt;
    dft[cnt] = x;
    int g = road[x];
    while (g != -1)
    {
        int now = mp[g][0];
        if (now != fa)
        {
            dfs(now, x);
        }
        g = mp[g][1];
    }
    out[x] = cnt;
}
void build(int l, int r, int t)
{
    tree[t] = n + 1;
    if (l == r)
    {
        return;
    }
    build(l, (l + r) / 2, t * 2);
    build((l + r) / 2 + 1, r, t * 2 + 1);
    return;
}
void change(int l, int r, int t, int po, int val)
{
    if (po < l || po > r)
        return;
    if (l == r)
    {
        tree[t] = val;
        return;
    }
    change(l, (l + r) / 2, t * 2, po, val);
    change((l + r) / 2 + 1, r, t * 2 + 1, po, val);
    tree[t] = min(tree[t * 2], tree[t * 2 + 1]);
    return;
}
int find(int l, int r, int t, int lpos, int rpos)
{
    if (lpos > r || rpos < l)
        return n + 1;
    if (lpos <= l && r <= rpos)
        return tree[t];
    return min(find(l, (l + r) / 2, t * 2, lpos, rpos), find((l + r) / 2 + 1, r, t * 2 + 1, lpos, rpos));
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cnt = 0;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            road[i] = -1;
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
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            pos[p[i]] = i;
        }
        for (int i = 1; i <= q; i++)
        {
            Node temp;
            cin >> temp.l >> temp.r >> temp.x;
            temp.id = i;
            a[i].first = in[temp.x];
            a[i].second = temp;
        }
        sort(a + 1, a + q + 1);
        build(1, n, 1);
        long long int p = n;
        for (int i = q; i >= 1; i--)
        {
            Node temp = a[i].second;
            while (p >= 1 && p >= a[i].first)
            {
                change(1, n, 1, pos[dft[p]], p);
                p--;
            }
            int val = find(1, n, 1, temp.l, temp.r);
            if (val <= out[temp.x])
                ans[temp.id] = 1;
            else
                ans[temp.id] = 0;
        }
        for (int i = 1; i <= q; i++)
        {
            if (ans[i] == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}