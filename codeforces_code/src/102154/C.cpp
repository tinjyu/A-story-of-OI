#include <iostream>
using namespace std;
long long int n;
long long int a[10005], b[10005], cnt, ans[100005][2];
void S(int l, int r)
{
    cnt++;
    ans[cnt][0] = l;
    ans[cnt][1] = r;
    int x[10005], y[10005], pp = 0, qq = 0;
    int len = r - l + 1, mid = (l + r - 1) / 2;
    for (int i = l; i <= mid; i++)
    {
        y[qq] = b[i];
        qq++;
    }
    for (int i = mid + 1; i <= r; i++)
    {
        x[pp] = b[i];
        pp++;
    }
    int p = 0, q = 0;
    for (int i = l; i <= r; i += 2)
    {
        b[i] = x[q];
        q++;
    }
    for (int i = l + 1; i <= r; i += 2)
    {
        b[i] = y[p];
        p++;
    }
    return;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = i;
    }
    for (int i = 1; i <= 10; i++)
    {
        S(1, n);
    }
    for (int i = n; i >= 1; i--)
    {
        while (true)
        {
            if (b[i] == a[i])
                break;
            for (int j = 1; j < i; j++)
            {
                if (a[i] == b[j])
                {
                    if (j * 2 >= i)
                    {
                        S(2 * j - i + 1, i);
                    }
                    else
                    {
                        S(1, 2 * j);
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    for (int i = cnt; i >= 1; i--)
        cout << ans[i][0] << " " << ans[i][1] << endl;
}