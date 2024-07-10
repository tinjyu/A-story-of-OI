#include <iostream>
#include <algorithm>
using namespace std;
long long int n, k, q, l[200005], r[200005], x[200005];
long long int cnt[200005];
string s;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        cin >> s;
        for (int i = 1; i <= n; i++)
            cnt[i] = 0;
        for (int i = 1; i <= k; i++)
            cin >> l[i];
        for (int i = 1; i <= k; i++)
            cin >> r[i];
        cin >> q;
        for (int i = 1; i <= q; i++)
            cin >> x[i];
        sort(x + 1, x + q + 1);
        int p = 1;
        for (int i = 1; i <= q; i++)
        {
            while (x[i] > r[p])
                p++;
            if (x[i] < r[p] + l[p] - x[i])
            {
                cnt[x[i]]++;
                cnt[r[p] + l[p] - x[i] + 1]++;
            }
            else
            {
                cnt[x[i] + 1]++;
                cnt[r[p] + l[p] - x[i]]++;
            }
        }
        p = 1;
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            while (i > r[p])
                p++;
            count += cnt[i];
            if (count % 2 == 1)
            {
                cout << s[r[p] + l[p] - i - 1];
            }
            else
                cout << s[i - 1];
        }
        cout << endl;
    }
}