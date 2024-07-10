#include <iostream>
using namespace std;
long long int n, m;
char mp[1005][1005];
long long int stx, sty;
long long int stdis[1005][1005];
long long int p, pp, t[5000005][5];
long long int dis[1005][1005];
long long int cnt[1005][1005], from[1005][1005][2][2], ans = 0;
void bfs1()
{
    while (p <= pp)
    {
        long long int x = t[p][0];
        long long int y = t[p][1];
        p++;
        for (int i = 1; i <= 4; i++)
        {
            long long int tempx = x;
            long long int tempy = y;
            if (i == 1)
                tempx++;
            if (i == 2)
                tempx--;
            if (i == 3)
                tempy++;
            if (i == 4)
                tempy--;
            if (tempx >= 1 && tempx <= n && tempy >= 1 && tempy <= m && stdis[tempx][tempy] == 1000000000000000000 && mp[tempx][tempy] == '.')
            {
                stdis[tempx][tempy] = stdis[x][y] + 1;
                pp++;
                t[pp][0] = tempx;
                t[pp][1] = tempy;
            }
        }
    }
    return;
}
void bfs()
{
    p = 1;
    while (p <= pp)
    {
        int x = t[p][0];
        int y = t[p][1];
        for (int i = 1; i <= 4; i++)
        {
            long long int tempx = x;
            long long int tempy = y;
            if (i == 1)
                tempx++;
            if (i == 2)
                tempx--;
            if (i == 3)
                tempy++;
            if (i == 4)
                tempy--;

            if (tempx >= 1 && tempx <= n && tempy >= 1 && tempy <= m && cnt[tempx][tempy] < 2 && mp[tempx][tempy] != '#')
            {
                if (cnt[tempx][tempy] == 1)
                {
                    if (from[tempx][tempy][0][0] == t[p][2] && from[tempx][tempy][0][1] == t[p][3])
                        continue;
                }
                pp++;
                t[pp][0] = tempx;
                t[pp][1] = tempy;
                t[pp][2] = t[p][2];
                t[pp][3] = t[p][3];
                t[pp][4] = t[p][4] + 1;
                from[tempx][tempy][cnt[tempx][tempy]][0] = t[p][2];
                from[tempx][tempy][cnt[tempx][tempy]][1] = t[p][3];
                dis[tempx][tempy] += t[pp][4];
                cnt[tempx][tempy]++;
            }
        }
        p++;
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> mp[i][j];
                if (mp[i][j] == '.')
                    ans++;
                if (mp[i][j] == 'V')
                {
                    stx = i;
                    sty = j;
                    stdis[i][j] = 0;
                }
                else
                {
                    stdis[i][j] = 1000000000000000000;
                }
                dis[i][j] = 0;
                cnt[i][j] = 0;
            }
        }
        p = 1;
        pp = 1;
        t[p][0] = stx;
        t[p][1] = sty;
        bfs1();
        p = 0;
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            if (mp[1][i] != '#')
            {
                if (stdis[1][i] != 1000000000000000000)
                    count++;
                p++;
                t[p][0] = 1;
                t[p][1] = i;
            }
            if (mp[n][i] != '#')
            {
                if (stdis[n][i] != 1000000000000000000)
                    count++;
                p++;
                t[p][0] = n;
                t[p][1] = i;
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (mp[i][1] != '#')
            {
                if (stdis[i][1] != 1000000000000000000)
                    count++;
                p++;
                t[p][0] = i;
                t[p][1] = 1;
            }
            if (mp[i][m] != '#')
            {
                if (stdis[i][m] != 1000000000000000000)
                    count++;
                p++;
                t[p][0] = i;
                t[p][1] = m;
            }
        }
        if (count == 0)
        {
            cout << ans << endl;
            continue;
        }
        if (count == 1)
        {
            long long int mi = 10000000000;
            for (int i = 1; i <= n; i++)
            {
                mi = min(mi, stdis[i][1]);
                mi = min(mi, stdis[i][m]);
            }
            for (int i = 1; i <= m; i++)
            {
                mi = min(mi, stdis[1][i]);
                mi = min(mi, stdis[n][i]);
            }
            cout << ans - mi << endl;
            continue;
        }
        pp = p;
        for (int i = 1; i <= p; i++)
        {
            int x = t[i][0], y = t[i][1];
            cnt[x][y] = 1;
            from[x][y][0][0] = x;
            from[x][y][0][1] = y;
            t[i][2] = x;
            t[i][3] = y;
            t[i][4] = 0;
            dis[x][y] = 0;
        }
        bfs();
        long long int mi = 10000000000;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                mi = min(mi, dis[i][j] + stdis[i][j]);
            }
        }
        cout << ans - mi << endl;
    }
}