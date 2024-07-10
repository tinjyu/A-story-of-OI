#include <iostream>
using namespace std;
long long int a[1000005], b[1000005], c[1000005], st[100005], en[100005];
int main()
{
    int n = 10;
    for (int i = 1; i <= n; i++)
    {
        cin >> st[i] >> en[i];
        en[i] += st[i] - 1;
    }

    while (true)
    {
        int cnt = 1;
        cin >> a[cnt] >> b[cnt] >> c[cnt];
        while (a[cnt] != 0 || b[cnt] != 0 || c[cnt] != 0)
        {
            c[cnt] += b[cnt] - 1;
            cnt++;
            cin >> a[cnt] >> b[cnt] >> c[cnt];
        }
        cnt--;
        long long int mi = 999999999999999;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= cnt; j++)
            {
                if (en[i] < b[j] || st[i] > c[j])
                    continue;
                if (st[i] < b[j] && c[j] < en[i])
                {
                    n++;
                    st[n] = st[i];
                    en[n] = b[j] - 1;
                    n++;
                    st[n] = c[j] + 1;
                    en[n] = en[i];
                    st[i] = b[j];
                    en[i] = c[j];
                    break;
                }
                else if (b[j] <= st[i] && c[j] < en[i])
                {
                    n++;
                    st[n] = c[j] + 1;
                    en[n] = en[i];
                    en[i] = c[j];
                }
                else if (st[i] < b[j] && en[i] <= c[j])
                {
                    n++;
                    st[n] = st[i];
                    en[n] = b[j] - 1;
                    st[i] = b[j];
                }

                if (b[j] <= st[i] && en[i] <= c[j])
                {
                    cout << st[i] << " " << en[i] << " " << b[j] << " " << a[j] << endl;
                    st[i] -= b[j] - a[j];
                    en[i] -= b[j] - a[j];
                    break;
                }
            }
            mi = min(mi, st[i]);
            cout << st[i] << " " << en[i] << endl;
        }

        cout << mi << endl;
    }
}