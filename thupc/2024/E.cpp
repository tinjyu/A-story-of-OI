#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
long long int n, a[1000005], b[1000005], c[1000005];
pair<long long int, long long int> pa[1000005];
int main()
{
    long long int sum = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &b[i]);
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &c[i]);
        if (a[i] == 0)
        {
            num++;
            if (b[i] == 1)
            {
                pa[num].first = 10000000000000;
            }
            else
                pa[num].first = c[i];
            pa[num].second = i;
        }
    }
    sort(pa + 1, pa + num + 1);
    long long int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 0 && b[i] > 0)
        {
            a[i] += c[i];
            sum += min(a[i], b[i]);
            cnt += min(a[i], b[i]);
        }
        else if (a[i] != 0)
            a[i] += c[i];
    }
    long long int used = 0;
    for (int j = num; j >= 1; j--)
    {
        int i = pa[j].second;
        if (cnt > 0 && b[i] > 0)
        {
            a[i] = 1;
            a[i] += c[i];
            sum += min(a[i], b[i]);
            cnt--;
            used++;
            cnt += min(a[i], b[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 0)
            cout << sum - min(a[i], b[i]) + a[i] - used << " ";
        else if (sum > 0)
            cout << sum + c[i] - used << " ";
        else
            cout << '0' << " ";
    }
    cout << endl;
    long long int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i];
    }
    for (int i = num; i >= 1; i--)
    {
        if (cnt <= 0)
            break;
        if (b[pa[i].second] != 0)
            continue;
        ans += c[pa[i].second];
        cnt--;
    }
    cout << ans - used << endl;
}