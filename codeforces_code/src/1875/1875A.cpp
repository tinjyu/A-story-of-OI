#include <iostream>
using namespace std;
long long int a, b, n;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> n;
        long long int ans = b;
        for (int i = 1; i <= n; i++)
        {
            long long int x;
            cin >> x;
            ans += min(x, a - 1);
        }
        cout << ans << endl;
    }
}