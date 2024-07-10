#include <iostream>
using namespace std;
long long int n;
char ch[1005][1005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> ch[i][j];
            }
        }
        long long int ans = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            for (int j = 1; j <= n / 2; j++)
            {
                char mx = 'a';
                mx = max(mx, ch[i][j]);
                mx = max(mx, ch[j][n - i + 1]);
                mx = max(mx, ch[n - i + 1][n + 1 - j]);
                mx = max(mx, ch[n + 1 - j][i]);
                ans += 4 * mx - ch[i][j] - ch[j][n - i + 1] - ch[n - i + 1][n + 1 - j] - ch[n + 1 - j][i];
            }
        }
        cout << ans << endl;
    }
}