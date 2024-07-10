#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int mp[1005][1005];
int main()
{
    for (int i = 1; i <= 99; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            mp[i][j + 1] = s[j] - '0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= 99; i++)
    {
        for (int j = 1; j <= 99; j++)
        {
            int flag = 0;
            for (int k = 1; k < j; k++)
            {
                if (mp[i][k] >= mp[i][j])
                    flag = 1;
            }
            if (flag == 0)
            {
                ans++;
                continue;
            }
            flag = 0;
            for (int k = j + 1; k <= 99; k++)
            {
                if (mp[i][k] >= mp[i][j])
                    flag = 1;
            }
            if (flag == 0)
            {
                ans++;
                continue;
            }
            flag = 0;
            for (int k = 1; k < i; k++)
            {
                if (mp[k][j] >= mp[i][j])
                    flag = 1;
            }
            if (flag == 0)
            {
                ans++;
                continue;
            }
            flag = 0;
            for (int k = i + 1; k <= 99; k++)
            {
                if (mp[k][j] >= mp[i][j])
                    flag = 1;
            }
            if (flag == 0)
            {
                ans++;
                continue;
            }
        }
    }
    cout << ans << endl;
}