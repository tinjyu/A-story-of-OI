#include <iostream>
using namespace std;
long long int n, m, k;
char ans1[20][20], ans2[20][20];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        if (k % 2 != (n + m) % 2 || k < n + m - 2)
        {
            cout << "No" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ans1[i][j] = 'R';
                ans2[i][j] = 'B';
            }
        }
        for (int i = 1; i < m; i++)
        {
            if (i % 2 == 0)
            {
                ans1[1][i] = 'R';
            }
            else
                ans1[1][i] = 'B';
        }
        for (int i = 1; i < n; i++)
        {
            if ((i + m) % 2 == 1)
            {
                ans2[i][m] = 'R';
            }
            else
                ans2[i][m] = 'B';
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                cout << ans1[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << ans2[i][j] << " ";
            }
            cout << endl;
        }
    }
}