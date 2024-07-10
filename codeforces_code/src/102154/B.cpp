#include <iostream>
using namespace std;
long long int n, a[10000005];
long long int t[1000005][2], p = 0, pos[1000005];
long long int mx[1000005][25][2];
long long int bits[300004];
int get(int l, int r)
{
    int len = r - l + 1;
    int x = bits[len], y = 1 << x;
    // cout << x << " " << y << " " << l << " " << r << endl;
    // cout << mx[l][x][0] << " " << mx[3][1][0] << endl;
    if (mx[l][x][0] > mx[r - y + 1][x][0])
        return mx[l][x][1];
    return mx[r - y + 1][x][1];
}
int main()
{
    scanf("%lld", &n);
    bits[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        pos[i] = n + 1;
        mx[i][0][0] = a[i];
        mx[i][0][1] = i;
        if (i != 1)
            bits[i] = bits[i / 2] + 1;
    }
    int len = 1;
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j + len <= n; j++)
        {
            if (mx[j][i - 1][0] > mx[j + len][i - 1][0])
            {
                mx[j][i][0] = mx[j][i - 1][0];
                mx[j][i][1] = mx[j][i - 1][1];
            }
            else
            {
                mx[j][i][0] = mx[j + len][i - 1][0];
                mx[j][i][1] = mx[j + len][i - 1][1];
            }
        }
        len *= 2;
    }
    for (int i = 1; i <= n; i++)
    {
        while (p != 0 && a[i] < t[p][0])
        {
            pos[t[p][1]] = i;
            p--;
        }
        p++;
        t[p][0] = a[i];
        t[p][1] = i;
    }
    long long int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long long int mx = 0, p = 0;
        ans++;
        p = get(i, pos[i] - 1);
        // cout << p << endl;
        i = p;
    }
    cout << ans << endl;
    return 0;
}