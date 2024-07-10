#include <iostream>
using namespace std;
long long int a, b, c;
long long int solve()
{
    cin >> a >> b >> c;
    long long int ans = 0;
    long long int x = c / a + (c % a >= b);
    x *= 2;
    long long int y = c / a + (c % a >= b) * 2;
    ans = max(ans, min(x - 1, y));
    x = c / b + (c % b >= a);
    x *= 2;
    y = (c / b) * 2 + (c % b >= a);
    ans = max(ans, min(x - 1, y));
    if (c >= 2 * a)
    {
        c -= 2 * a;
        x = c / b + 2;
        x *= 2;
        y = (c / b) * 2 + 2;
        ans = max(ans, min(x - 1, y));
    }
    return ans;
}
int main()
{
    freopen("cheeseburger_corollary_2_input.txt", "r", stdin);
    freopen("cheeseburger_corollary_2_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}