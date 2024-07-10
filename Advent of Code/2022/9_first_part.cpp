#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long int mp[2005][2005];

int main()
{
    int sx = 1000, sy = 1000, tx = 1000, ty = 1000;
    for (int i = 1; i <= 2000; i++)
    {
        char c;
        int step;
        cin >> c >> step;
        for (int j = 1; j <= step; j++)
        {
            int tempx = sx, tempy = sy;
            if (c == 'D')
                tempx++;
            if (c == 'L')
                tempy--;
            if (c == 'R')
                tempy++;
            if (c == 'U')
                tempx--;
            if (max(abs(tempx - tx), abs(tempy - ty)) >= 2)
            {
                tx = sx;
                ty = sy;
            }
            sx = tempx;
            sy = tempy;
            mp[tx][ty] = 1;
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