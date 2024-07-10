#include <iostream>
#include <algorithm>
using namespace std;
long long int n, a[6000005], b[6000005];
long long int solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    long long int p = 1, q = n / 2 + n % 2 + 1;
    for (long long int i = 0; i < 2 * n; i++)
    {
        p = max(p, i + 1);
        q = max(n / 2 + n % 2 + i + 1, q);
        while (p <= n / 2 + i && a[p] < b[p])
            p++;
        while (q <= n + i && a[q] > b[q])
        {
            q++;
        }
        if (p > n / 2 + i && q > n + i)
        {
            int flag = 0;
            int pp = i + 1, qq = n + i;
            for (int j = i + 1; j <= n + i; j++)
            {
                if (a[pp] != b[qq])
                    flag = 1;
                pp++;
                qq--;
            }
            if (flag == 0)
                return i;
        }
        a[n + i + 1] = b[i + 1];
        b[n + i + 1] = a[i + 1];
    }
    return -1;
}
int main()
{
    freopen("meta_game_input.txt", "r", stdin);
    freopen("meta_game_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}