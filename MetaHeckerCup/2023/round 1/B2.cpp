#include <iostream>
#include <algorithm>
using namespace std;
long long int n, m, x[1000005];
long long int g[1000005];
long long int ans = 100005;
void dfs(long long int num, long long int cnt, long long int sum)
{
    if (num > 2000000)
        return;
    if (sum > 41 || cnt >= ans)
        return;
    if (num == 1)
    {
        if (cnt + 41 - sum < ans)
        {
            ans = cnt + 41 - sum;
            for (int i = 1; i <= cnt; i++)
                x[i] = g[i];
            for (int i = cnt + 1; i <= ans; i++)
                x[i] = 1;
        }
        return;
    }
    for (int i = 41; i >= 2; i--)
    {
        if (num % i == 0)
        {
            g[cnt + 1] = i;
            dfs(num / i, cnt + 1, sum + i);
        }
    }
    return;
}
string solve(int id)
{
    cin >> n;
    ans = 100005;
    dfs(n, 0, 0);
    cout << "Case #" << id << ": ";
    if (ans >= 1000)
        cout << "-1" << endl;
    else
    {
        cout << ans << " ";
        for (int i = 1; i <= ans; i++)
            cout << x[i] << " ";
        cout << endl;
    }
}
int main()
{
    freopen("sum_41_chapter_2_input.txt", "r", stdin);
    freopen("sum_41_chapter_2_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
}