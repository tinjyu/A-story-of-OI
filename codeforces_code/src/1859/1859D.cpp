#include <iostream>
using namespace std;
long long int n, ans[100005], a[1000005], b[1000005], l[1000005], r[1000005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i] >> r[i] >> a[i] >> b[i];
        }
    }
}