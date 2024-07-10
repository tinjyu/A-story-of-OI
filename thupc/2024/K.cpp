#include <iostream>
using namespace std;
char mp[10][10];
int x1, x2, y1, y2;
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        x1 = -1;
        x2 = 6;
        y1 = -1;
        y2 = 6;
        int cnt = 0;
        int flag = 0;
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                cin >> mp[i][j];
                if (mp[i][j] == 'o')
                {
                    cnt++;
                    y1 = max(j, y1);
                    y2 = min(j, y2);
                    x1 = max(i, x1);
                    x2 = min(i, x2);
                }
            }
        }
        if (cnt == 2 || (cnt == 4 && (x1 - x2 + 1) * (y1 - y2 + 1) == 6))
            cout << "Far" << endl;
        else
            cout << "Away" << endl;
    }
}