#include <iostream>
#include <algorithm>
using namespace std;
long long int ans = 0, num = 0;
long long int a[10004], pos[100005];
char c[10005];
string s;
void dfs(int p, int pre)
{
    if (pre > s.length() + 1)
        return;

    if (p == num + 1)
    {
        for (int i = 0; i < s.length(); i++)
        {
            c[i] = '.';
        }
        for (int i = 1; i <= num; i++)
        {
            for (int j = pos[i]; j < pos[i] + a[i]; j++)
                c[j] = '#';
        }
        int flag = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.' && c[i] == '#')
                flag = 0;
            if (s[i] == '#' && c[i] == '.')
                flag = 0;
        }
        ans += flag;
        return;
    }

    for (int i = pre; i < s.length(); i++)
    {
        pos[p] = i;
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
        t += ',';
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
        int preans = ans;
        dfs(1, 0);
        cout << ans - preans << endl;
    }
    cout << ans << endl;
}