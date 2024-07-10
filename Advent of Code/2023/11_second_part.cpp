#include <iostream>
#include <algorithm>
using namespace std;
char mp[1005][1005];
int mp2[1005][1005];
long long int tagx[1005], tagy[1005];
long long int x[10005], y[10005];
long long int ans = 0;
int main()
{
    int n = 140, m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        m = s.length();
        for (int j = 1; j <= m; j++)
        {
            mp[i][j] = s[j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int flag = 1;
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == '#')
                flag = 0;
        }
        tagx[i] = flag;
    }
    for (int j = 1; j <= m; j++)
    {
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (mp[i][j] == '#')
                flag = 0;
        }
        tagy[j] = flag;
    }
    long long int num = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j] == '#')
            {
                num++;
                x[num] = i;
                y[num] = j;
            }
        }
    }
    long long int ans = 0;
    for (int i = 1; i <= num; i++)
    {
        for (int j = i + 1; j <= num; j++)
        {
            for (int k = min(x[i], x[j]) + 1; k <= max(x[i], x[j]); k++)
            {
                if (tagx[k] == 1)
                    ans += 1000000;
                else
                    ans++;
            }
            for (int k = min(y[i], y[j]) + 1; k <= max(y[i], y[j]); k++)
            {
                if (tagy[k] == 1)
                    ans += 1000000;
                else
                    ans++;
            }
        }
    }
    cout << ans << endl;
}