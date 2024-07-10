#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
long long int n, p[1000005], m[1000005], l[1000005], r[1000005];
map<string, int> s;
int len, ans;
vector<int> id[3000005];
long long int road[1000005], mp[1000005][2], temp = 0;
pair<int, int> pa[3000005];
int cnt = 0;
void dfs(int x)
{
    int g = road[x];
    int soncnt = 0;
    if (g == -1)
    {
        cnt++;
        l[x] = cnt;
        r[x] = cnt;
        return;
    }
    l[x] = 1000000000;
    r[x] = 0;
    while (g != -1)
    {
        int now = mp[g][0];
        dfs(now);
        l[x] = min(l[x], l[now]);
        r[x] = max(r[x], r[now]);
        g = mp[g][1];
    }
    return;
}
priority_queue<pair<int, int>> q;
long long int solve()
{
    cnt = 0;
    s.clear();
    cin >> n;
    road[1] = -1;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        road[i] = -1;
    }
    for (int i = 2; i <= n; i++)
    {
        mp[i][0] = i;
        mp[i][1] = road[p[i]];
        road[p[i]] = i;
    }
    len = 0;

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &m[i]);
        for (int j = 1; j <= m[i]; j++)
        {
            string tmp;
            cin >> tmp;
            if (s.find(tmp) == s.end())
            {
                len++;
                s[tmp] = len;
            }
            id[s[tmp]].push_back(i);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        int g = road[i];
        int soncnt = 0;
        if (g == -1)
        {
            cnt++;
            l[i] = cnt;
            r[i] = cnt;
        }
        l[i] = 1000000000;
        r[i] = 0;
        while (g != -1)
        {
            int now = mp[g][0];
            l[i] = min(l[i], l[now]);
            r[i] = max(r[i], r[now]);
            g = mp[g][1];
        }
    }
    ans = 0;
    for (int i = 1; i <= len; i++)
    {
        int flag = 0;
        cout << i << " " << id[i].size() << " " << r[1] << endl;
        if (id[i].size() < r[1])
            continue;
        for (int j = 0; j < id[i].size(); j++)
        {
            pa[j].first = l[id[i][j]];
            pa[j].second = r[id[i][j]];
            cout << id[i][j] << " " << pa[j].first << " " << pa[j].second << endl;
        }
        sort(pa, pa + id[i].size());
        while (!q.empty())
            q.pop();
        int pp = 0;
        int prel = 1, prer = r[1] + 1;

        for (int j = 1; j <= r[1]; j++)
        {
            if (j > prer)
            {
                prel = 1;
                prer = r[1] + 1;
            }
            while (pp < id[i].size() && pa[pp].first == j)
            {
                q.push(make_pair(-pa[pp].second, pa[pp].first));
                pp++;
            }
            while (!q.empty() && (-q.top().first < j || (-q.top().first == prer && q.top().second <= prel)))
            {
                q.pop();
            }
            if (q.empty())
            {
                flag = 1;
                break;
            }
            prer = -q.top().first;
            prel = q.top().second;
            q.pop();
        }
        if (flag == 0)
            ans++;
    }

    s.clear();
    for (int i = 1; i <= len; i++)
    {
        id[i].clear();
    }
    return ans;
}
int main()
{
    // freopen("wiki_race_input.txt", "r", stdin);
    // freopen("wiki_race_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        temp = i;
        cout << "Case #" << i << ": " << solve() << endl;
    }
}