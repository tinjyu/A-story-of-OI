#include <iostream>
using namespace std;
long long int n, a[105][105], cnt[105];
long long int tag[105], tag2[105];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= 50; i++)
            tag[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> cnt[i];
            for (int j = 1; j <= cnt[i]; j++)
            {
                cin >> a[i][j];
                tag[a[i][j]]++;
            }
        }
        long long int ans = 0;
        for (int i = 1; i <= 50; i++)
        {
            if (tag[i] != 0)
            {
                for (int j = 1; j <= 50; j++)
                {
                    tag2[j] = 0;
                }
                long long int tempans = 0;
                for (int j = 1; j <= n; j++)
                {
                    int flag = 0;
                    for (int k = 1; k <= cnt[j]; k++)
                    {
                        if (a[j][k] == i)
                            flag = 1;
                    }
                    if (flag == 1)
                        continue;
                    for (int k = 1; k <= cnt[j]; k++)
                    {
                        if (tag2[a[j][k]] == 0)
                            tempans++;
                        tag2[a[j][k]] = 1;
                    }
                }
                ans = max(tempans, ans);
            }
        }
        cout << ans << endl;
    }
}