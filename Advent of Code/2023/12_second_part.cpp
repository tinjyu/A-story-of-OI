#include <iostream>
#include <algorithm>
using namespace std;
long long int ans = 0, num = 0;
long long int a[10004], pos[100005];
long long int suf[100005];
char c[10005];
long long int dp[1000][1000];
string s;
void dfs(int p, int pre)
{
    for (int i = pos[p - 1]; i < pos[p - 1] + a[p - 1]; i++)
    {
        c[i] = '#';
    }
    int flag = 1;
    for (int i = pos[p - 2]; i < pos[p - 1] + a[p - 1]; i++)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.' && c[i] == '#')
                flag = 0;
            if (s[i] == '#' && c[i] == '.')
                flag = 0;
        }
    }
    if (flag == 0)
    {
        for (int i = pos[p - 1]; i < pos[p - 1] + a[p - 1]; i++)
        {
            c[i] = '.';
        }
    }
    if (p == num + 1)
    {
        int flag = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.' && c[i] == '#')
                flag = 0;
            if (s[i] == '#' && c[i] == '.')
                flag = 0;
        }
        ans += flag;
        for (int i = pos[p - 1]; i < pos[p - 1] + a[p - 1]; i++)
        {
            c[i] = '.';
        }
        return;
    }

    for (int i = pre; i < s.length() - suf[p] + 1; i++)
    {
        pos[p] = i;
        // cout << p << " " << i << endl;
        dfs(p + 1, i + a[p] + 1);
    }
}
int main()
{
    long long int n = 1000;
    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> s >> t;
        s = s + "?" + s + "?" + s + "?" + s + "?" + s;
        s = " " + s;
        t += ",";
        t = t + t + t + t + t;
        int x = 0;
        num = 0;
        for (int j = 0; j < t.length(); j++)
        {
            if (t[j] == ',')
            {
                num++;
                a[num] = x;
                x = 0;
                continue;
            }
            x *= 10;
            x += t[j] - '0';
        }
        for (int i = 0; i <= num; i++)
        {
            for (int j = 0; j <= s.length(); j++)
                dp[i][j] = 0;
        }

        dp[0][0] = 1;
        for (int i = 1; i <= num; i++)
        {
            for (int j = 1; j <= s.length(); j++)
            {
                // if (j <= 10)
                //     cout << dp[i][j] << " ";
                int flag = 0;
                for (int k = j; k < j + a[i]; k++)
                {
                    if (k >= s.length())
                    {
                        flag = 1;
                        break;
                    }
                    if (s[k] == '.')
                        flag = 1;
                }
                if (j + a[i] < s.length() && s[j + a[i]] == '#')
                    flag = 1;
                if (flag == 1)
                    continue;
                for (int k = j; k >= 1; k--)
                {
                    dp[i][j + a[i]] += dp[i - 1][k - 1];
                    if (s[k - 1] == '#')
                        break;
                }
            }
            // cout << endl;
        }
        long long int sum = 0;
        for (int j = s.length(); j >= 0; j--)
        {
            ans += dp[num][j];
            sum += dp[num][j];
            if (s[j] == '#')
                break;
        }
        cout << sum << endl;
        cout << ans << endl;
    }

    cout << ans << endl;
}