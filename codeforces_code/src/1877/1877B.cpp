#include <iostream>
#include <algorithm>
using namespace std;
long long int n, p;
pair<long long int, long long int> pa[1000005];
int main()
{
    int T;
    cin >> T;
    int id = 0;
    while (T--)
    {
        id++;
        cin >> n >> p;
        for (int i = 1; i <= n; i++)
        {
            cin >> pa[i].second;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> pa[i].first;
        }
        n++;
        pa[n].first = p;
        pa[n].second = 10000000;
        sort(pa + 1, pa + n + 1);
        if (p <= pa[1].first)
        {
            cout << p * (n - 1) << endl;
            continue;
        }
        long long int ans = p, rem = n - 2;
        for (int i = 1; i <= n; i++)
        {
            if (pa[i].second >= rem)
            {
                ans += rem * pa[i].first;
                break;
            }
            rem -= pa[i].second;
            ans += pa[i].second * pa[i].first;
        }
        cout << ans << endl;
    }
}