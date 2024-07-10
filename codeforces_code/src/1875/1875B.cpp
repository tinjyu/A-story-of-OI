#include <iostream>
#include <algorithm>

using namespace std;
long long int k, a[10005], b[10005], n, m;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        if (b[m] > a[1])
            swap(a[1], b[m]);
        if (k >= 2)
        {
            int p = 1, q = 1;
            if (b[m] < b[1])
                q = m;
            if (a[n] > a[1])
                p = n;
            if (a[p] > b[q])
                swap(a[p], b[q]);
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        if (k >= 3 && k % 2 == 1)
        {
            a[1] = max(a[1], b[m]);
        }
        long long int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i];
        cout << sum << endl;
    }
}