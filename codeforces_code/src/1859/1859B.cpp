#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a[25005];
int n, m[25005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> m[i];
            a[i].resize(m[i]);
            for (int j = 0; j < m[i]; j++)
            {
                cin >> a[i][j];
            }
            sort(a[i].begin(), a[i].end());
        }
        long long int ans = 0;
        int mi1 = 1 << 30, mi2 = 1 << 30;
        for (int i = 1; i <= n; i++)
        {
            ans += a[i][1];
            mi1 = min(mi1, a[i][0]);
            mi2 = min(mi2, a[i][1]);
        }
        cout << ans + mi1 - mi2 << endl;
    }
}