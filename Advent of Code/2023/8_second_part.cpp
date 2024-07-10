#include <iostream>
#include <algorithm>
using namespace std;
long long int type[1005], cost[100005];
string s[10005];

int main()
{
    long long int n = 1000;
    long long int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> cost[i];
        for (int j = 0; j < 5; j++)
        {
            if (s[i][j] == 'A')
                s[i][j] = 'E';
            if (s[i][j] == 'K')
                s[i][j] = 'D';
            if (s[i][j] == 'Q')
                s[i][j] = 'C';
            if (s[i][j] == 'J')
                s[i][j] = '0';
            if (s[i][j] == 'T')
                s[i][j] = 'A';
        }
        string temp = s[i];
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (temp[k] < temp[k + 1])
                    swap(temp[k], temp[k + 1]);
            }
        }
        int cnt[7] = {0, 0, 0, 0, 0, 0, 0}, num = 0, count = 0;
        int ct = 0;
        temp += ' ';
        for (int j = 0; j < 5; j++)
        {
            count++;
            if (temp[j] == '0')
            {
                ct++;
                count = 0;
            }
            if (temp[j] != temp[j + 1])
            {
                if (count == 0)
                    continue;
                num++;
                cnt[num] = count;
                count = 0;
            }
        }
        if (num == 0)
            num++;
        sort(cnt + 1, cnt + 1 + num);
        cnt[num] += ct;
        if (cnt[1] == 5)
            type[i] = 10;
        else if (cnt[1] == 4 || cnt[2] == 4)
            type[i] = 9;
        else if ((cnt[1] == 3 && cnt[2] == 2) || (cnt[1] == 2 && cnt[2] == 3))
            type[i] = 8;
        else if (cnt[1] == 3 || cnt[2] == 3 || cnt[3] == 3)
            type[i] = 7;
        else if ((cnt[1] == 2 && cnt[2] == 2) || (cnt[1] == 2 && cnt[3] == 2) || (cnt[2] == 2 && cnt[3] == 2))
            type[i] = 6;
        else if (cnt[1] == 2 || cnt[2] == 2 || cnt[3] == 2 || cnt[4] == 2)
            type[i] = 5;
        else
            type[i] = 4;
        cout << type[i] << " " << temp << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (type[j] > type[j + 1] || (type[j] == type[j + 1] && s[j] > s[j + 1]))

            {
                swap(type[j], type[j + 1]);
                swap(s[j], s[j + 1]);
                swap(cost[j], cost[j + 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << s[i] << endl;
        ans += cost[i] * i;
    }
    cout << ans << endl;
}