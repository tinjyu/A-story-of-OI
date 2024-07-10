#include <iostream>
#include <algorithm>
using namespace std;
long long int type[1005], cost[100005];
long long int num[1005][1005];
int main()
{
    int T = 200;
    long long int ans = 0;
    while (T--)
    {
        int n = 21;
        for (int i = 1; i <= n; i++)
        {
            cin >> num[1][i];
        }
        int len = n, id = 2;
        long long int sum = 0;
        while (true)
        {
            int flag = 0;
            for (int i = 1; i < len; i++)
            {
                num[id][i] = num[id - 1][i + 1] - num[id - 1][i];
                if (num[id][i] != 0)
                    flag = 1;
            }
            if (flag == 0)
                break;
            len--;
            id++;
        }
        long long int temp = 0;
        for (int i = id - 1; i >= 1; i--)
        {
            temp = num[i][1] - temp;
        }
        ans += temp;
        cout << ans << endl;
    }
    cout << ans << endl;
}