#include <iostream>
using namespace std;
long long int n, a[1000005], d[1000005][30];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            d[i][0] = a[i];
        }
        for (int i = 1; i <= 25; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j + (1 << (i - 1)) <= n)
                {
                    d[j][i] = d[j + (1 << (i - 1))][i - 1] & d[j][i - 1];
                }
                else
                    d[j][i] = 0;
            }
        }
        int q;
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            long long int l, k;
            long long int now = (1 << 30) - 1;
            cin >> l >> k;
            long long int st = l;
            for (int j = 25; j >= 0; j--)
            {
                if ((now & d[st][j]) >= k)
                {
                    now = now & d[st][j];
                    st += (1 << j);
                }
                if (st > n)
                    break;
            }
            if (st == l)
                cout << "-1"
                     << " ";
            else
                cout << st - 1 << " ";
        }
        cout << endl;
    }
}