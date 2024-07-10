#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int mp[1009][1009];
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
            int cnt = 0, temp = 1;
            for (int k = j - 1; k >= 1; k--)
            {
                cnt++;
                if (mp[i][k] >= mp[i][j])
                    break;
            }
            temp *= cnt;
            cnt = 0;
            for (int k = j + 1; k <= 99; k++)
            {
                cnt++;
                if (mp[i][k] >= mp[i][j])
                    break;
            }
            temp *= cnt;
            cnt = 0;
            for (int k = i - 1; k >= 1; k--)
            {
                cnt++;
                if (mp[k][j] >= mp[i][j])
                    break;
            }
            temp *= cnt;
            cnt = 0;
            for (int k = i + 1; k <= 99; k++)
            {
                cnt++;
                if (mp[k][j] >= mp[i][j])
                    break;
            }
            temp *= cnt;
            cnt = 0;
            ans = max(temp, ans);
        }
    }
    cout << ans << endl;
}