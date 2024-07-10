#include <iostream>
#include <algorithm>
using namespace std;
char mp[150][200];
long long int ans = 0;
void dfs(int x, int y, int from)
{
    cout << x << " " << y << endl;
    ans++;
    if (mp[x][y] == '|')
    {
        if (from == 2)
            dfs(x - 1, y, 2);
        else
            dfs(x + 1, y, 4);
    }
    if (mp[x][y] == '-')
    {
        if (from == 3)
            dfs(x, y + 1, 3);
        else
            dfs(x, y - 1, 1);
    }
    if (mp[x][y] == 'L')
    {
        if (from == 4)
            dfs(x, y + 1, 3);
        else
            dfs(x - 1, y, 2);
    }
    if (mp[x][y] == 'J')
    {
        if (from == 4)
            dfs(x, y - 1, 1);
        else
            dfs(x - 1, y, 2);
    }
    if (mp[x][y] == '7')
    {
        if (from == 3)
            dfs(x + 1, y, 4);
        else
            dfs(x, y - 1, 1);
    }
    if (mp[x][y] == 'F')
    {
        if (from == 2)
            dfs(x, y + 1, 3);
        else
            dfs(x + 1, y, 4);
    }
    if (mp[x][y] == 'S')
        return;
}
int main()
{
    int n = 140, m;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        m = s.length();
        for (int j = 1; j <= m; j++)
        {
            mp[i][j] = s[j - 1];
            if (mp[i][j] == 'S')
            {
                x = i;
                y = j;
            }
        }
    }
    dfs(x - 1, y, 2);
    cout << ans << endl;
}