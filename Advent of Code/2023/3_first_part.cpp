#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char mp[200][200];
int main()
{
    int m;
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            mp[i][j] = '.';
        }
    }
    for (int i = 1; i <= 140; i++)
    {
        string s;
        cin >> s;
        m = s.length();
        for (int j = 0; j < m; j++)
        {
            mp[i][j + 1] = s[j];
        }
    }
    long long int ans = 0;
    for (int i = 1; i <= 140; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] <= '9' && mp[i][j] >= '0')
            {
                int l = j, r = j;
                long long int num = 0;
                while (mp[i][r] <= '9' && mp[i][r] >= '0')
                {
                    num *= 10;
                    num += mp[i][r] - '0';
                    r++;
                }
                r--;
                int flag = 0;
                for (int j = l - 1; j <= r + 1; j++)
                {
                    if (mp[i][j] != '.' && !(mp[i][j] <= '9' && mp[i][j] >= '0'))
                        flag = 1;
                    if (mp[i - 1][j] != '.' && !(mp[i - 1][j] <= '9' && mp[i - 1][j] >= '0'))
                        flag = 1;
                    if (mp[i + 1][j] != '.' && !(mp[i + 1][j] <= '9' && mp[i + 1][j] >= '0'))
                        flag = 1;
                }
                ans += flag * num;
                cout << num << " " << flag << endl;
                j = r;
                continue;
            }
        }
    }
    cout << ans << endl;
}