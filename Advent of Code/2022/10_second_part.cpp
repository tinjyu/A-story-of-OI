#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
long long int mp[10][50];

int main()
{
    int xx = 0, y = 0;
    int ti = 0, ans = 0, x = 1;
    for (int i = 1; i <= 139; i++)
    {
        cout << xx << " " << y << " " << x << " " << ti << endl;
        string s;
        cin >> s;
        if (s == "noop")
        {
            ti++;
            if (x <= ti % 40 + 1 && x >= ti % 40 - 1)
            {
                mp[xx][y] = 1;
            }
            y++;
            if (y == 40)
            {
                xx++;
                y = 0;
            }
            continue;
        }
        int num = 0;
        cin >> num;
        ti++;
        if (x <= ti % 40 + 1 && x >= ti % 40 - 1)
        {
            mp[xx][y] = 1;
        }
        y++;
        if (y == 40)
        {
            xx++;
            y = 0;
        }

        x += num;
        ti++;
        if (x <= ti % 40 + 1 && x >= ti % 40 - 1)
        {
            mp[xx][y] = 1;
        }
        y++;
        if (y == 40)
        {
            xx++;
            y = 0;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            if (mp[i][j] == 1)
                cout << "#";
            else
                cout << ".";
        }
        cout << endl;
    }
    cout << ans << endl;
}