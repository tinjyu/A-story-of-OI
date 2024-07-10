#include <iostream>
#include <algorithm>
using namespace std;
long long int n, m, x[1000005];
double solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    sort(x + 1, x + n + 1);
    if (n == 5)
    {
        double st = double(x[1] + x[3]) / 2, en = double(x[n - 1] + x[n]) / 2;
        double ans = en - st;
        st = double(x[1] + x[2]) / 2, en = double(x[3] + x[n]) / 2;
        ans = max(ans, en - st);
        return ans;
    }
    double st = double(x[1] + x[2]) / 2, en = double(x[n - 1] + x[n]) / 2;
    return en - st;
}
int main()
{
    freopen("here_comes_santa_claus_input.txt", "r", stdin);
    freopen("here_comes_santa_claus_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}