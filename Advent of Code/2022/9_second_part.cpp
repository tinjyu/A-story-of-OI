#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long int mp[2005][2005];
long long int x[20], y[20];
int main()
{
    for (int i = 1; i <= 10; i++)
        x[i] = 1000, y[i] = 1000;
    for (int i = 1; i <= 2000; i++)
    {
        char c;
        int step;
        cin >> c >> step;
        for (int j = 1; j <= step; j++)
        {
            if (c == 'D')
                x[1]++;
            if (c == 'L')
                y[1]--;
            if (c == 'R')
                y[1]++;
            if (c == 'U')
                x[1]--;
            for (int k = 2; k <= 10; k++)
            {
                if (abs(x[k - 1] - x[k]) == 2 || abs(y[k - 1] - y[k]) == 2)
                {
                    if (x[k] > x[k - 1])
                        x[k]--;
                    if (x[k] < x[k - 1])
                        x[k]++;
                    if (y[k] > y[k - 1])
                        y[k]--;
                    if (y[k] < y[k - 1])
                        y[k]++;
                }
            }
            mp[x[10]][y[10]] = 1;
        }
    }
    long long int ans = 0;
    for (int i = 1; i <= 2000; i++)
    {
        for (int j = 1; j <= 2000; j++)
        {
            ans += mp[i][j];
        }
    }
    cout << ans << endl;
}