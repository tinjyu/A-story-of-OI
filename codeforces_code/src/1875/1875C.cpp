#include <iostream>
using namespace std;
long long int n, m;
long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        if (n % m == 0)
        {
            cout << 0 << endl;
            continue;
        }
        n %= m;
        long long int sum = gcd(n, m), ans = 0;
        n /= sum;
        m /= sum;
        if ((m & (m - 1)) != 0)
        {
            cout << "-1" << endl;
            continue;
        }
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans += (m - 1) * sum;
            }
            sum *= 2;
            n /= 2;
            m /= 2;
        }
        cout << ans << endl;
    }
}