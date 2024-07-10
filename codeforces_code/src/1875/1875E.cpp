#include <iostream>
using namespace std;
int dp[1000005];
int a[10], b[10], id = 0;
int mp[2000005][2], road[1000005], in[1000005];
int And[8] = {0, 1, 2, 3, 0, 1, 6, 7};
int Or[8] = {0, 1, 6, 7, 4, 5, 6, 7};
int Xory[8] = {0, 1, 2, 3, 6, 7, 4, 5};
int Xorm[8] = {0, 3, 2, 1, 4, 7, 6, 5};
int t[1000005], pp = 1, qq = 0;
int geta()
{
    int now = 0;
    for (int i = 7; i >= 0; i--)
    {
        now *= 5;
        now += a[i];
    }
    return now;
}
int getb()
{
    int now = 0;
    for (int i = 7; i >= 0; i--)
    {
        now *= 5;
        now += b[i];
    }
    return now;
}
void link(int nxt, int now)
{
    id++;
    mp[id][0] = now;
    mp[id][1] = road[nxt];
    road[nxt] = id;
    return;
}
void init(int p)
{
    if (p == 8)
    {
        int now = geta();
        int flag = 0;
        for (int i = 0; i <= 7; i++)
            b[i] = 4;
        for (int i = 0; i <= 7; i++)
        {
            if (a[i] == 4)
                continue;
            if (b[And[i]] == a[i] || b[And[i]] == 4)
            {
                b[And[i]] = a[i];
            }
            else
                flag = 1;
        }
        int nxt = getb();
        if (flag == 0)
            link(nxt, now);

        flag = 0;
        for (int i = 0; i <= 7; i++)
            b[i] = 4;
        for (int i = 0; i <= 7; i++)
        {
            if (a[i] == 4)
                continue;
            if (b[Or[i]] == a[i] || b[Or[i]] == 4)
            {
                b[Or[i]] = a[i];
            }
            else
                flag = 1;
        }
        nxt = getb();
        if (flag == 0)
            link(nxt, now);

        for (int i = 0; i <= 7; i++)
            b[i] = 4;
        for (int i = 0; i <= 7; i++)
            b[Xory[i]] = a[i];
        nxt = getb();
        link(nxt, now);

        for (int i = 0; i <= 7; i++)
            b[i] = 4;
        for (int i = 0; i <= 7; i++)
            b[Xorm[i]] = a[i];
        nxt = getb();
        link(nxt, now);

        return;
    }
    for (int i = 0; i < 5; i++)
    {
        a[p] = i;
        init(p + 1);
    }
}
void initbfs(int p)
{
    if (p == 8)
    {
        int now = geta();
        dp[now] = 0;
        in[now] = 1;
        qq++;
        t[qq] = now;
        return;
    }
    a[p] = p / 2;
    initbfs(p + 1);
    a[p] = 4;
    initbfs(p + 1);
}
int main()
{
    for (int i = 0; i <= 1000000; i++)
    {
        road[i] = -1;
        dp[i] = 1000000000;
    }
    init(0);
    initbfs(0);
    while (pp <= qq)
    {
        int x = t[pp];
        int g = road[x];
        while (g != -1)
        {
            int now = mp[g][0];
            if (dp[now] > dp[x] + 1)
            {
                dp[now] = dp[x] + 1;
                if (!in[now])
                {
                    in[now] = 1;
                    t[qq] = now;
                    qq++;
                }
            }
            g = mp[g][1];
        }
        pp++;
    }

    int T;
    cin >> T;
    while (T--)
    {
        int x, y, c, d, m;
        cin >> x >> y >> c >> d >> m;
        for (int i = 0; i < 8; i++)
            a[i] = 4;
        int flag = 0;
        for (int i = 0; i < 32; i++)
        {
            if (x == 0 && y == 0 && c == 0 && d == 0 && m == 0)
                break;
            int now = x % 2 * 4 + y % 2 * 2 + m % 2;
            int val = c % 2 * 2 + d % 2;
            if (a[now] == val || a[now] == 4)
            {
                a[now] = val;
            }
            else
            {
                flag = 1;
                break;
            }
            x /= 2, y /= 2, c /= 2, d /= 2, m /= 2;
        }
        if (flag == 1)
        {
            cout << "-1" << endl;
            continue;
        }
        else
        {
            int now = geta();
            if (dp[now] == 1000000000)
                cout << "-1" << endl;
            else
                cout << dp[now] << endl;
        }
    }

    return 0;
}