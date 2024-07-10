#include <iostream>
#include <algorithm>
using namespace std;
long long int r, c, id = 0, temp[3005][3005], tag[3005][3005], wcnt = 0, ecnt = 0, ans[3005][3005], tarx, tary, t[1000005][2];
char mp[3005][3005];

void bfs(int x, int y)
{
    int p = 0, pp = 0;
    t[pp][0] = x;
    t[pp][1] = y;
    while (p <= pp)
    {
        x = t[p][0];
        y = t[p][1];
        wcnt++;
        tag[x][y] = id;
        for (int i = 1; i <= 4; i++)
        {
            int tmpx = x, tmpy = y;
            if (i == 1)
                tmpx++;
            if (i == 2)
                tmpy++;
            if (i == 3)
                tmpx--;
            if (i == 4)
                tmpy--;
            if (tmpx <= 0 || tmpy <= 0 || tmpx > r || tmpy > c)
                continue;
            if (mp[tmpx][tmpy] == '.' && tag[tmpx][tmpy] != -id)
            {
                tag[tmpx][tmpy] = -id;
                ecnt++;
                tarx = tmpx;
                tary = tmpy;
            }
            if (mp[tmpx][tmpy] == 'W' && tag[tmpx][tmpy] != id)
            {
                pp++;
                t[pp][0] = tmpx;
                t[pp][1] = tmpy;
            }
        }
        p++;
    }
    return;
}

string solve()
{
    id = 0;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> mp[i][j];
            tag[i][j] = 0;
            ans[i][j] = 0;
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (mp[i][j] == 'W' && tag[i][j] == 0)
            {
                wcnt = 0;
                ecnt = 0;
                id++;
                bfs(i, j);
                if (ecnt == 1)
                {
                    ans[tarx][tary] += wcnt;
                }
            }
        }
    }
    long long int finans = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            // cout << ans[i][j] << " ";
            finans = max(ans[i][j], finans);
        }
        // cout << endl;
    }
    if (finans >= 1)
        return "YES";
    else
        return "NO";
}
int main()
{
    freopen("ready_go_part_1_input.txt", "r", stdin);
    freopen("ready_go_part_1_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}