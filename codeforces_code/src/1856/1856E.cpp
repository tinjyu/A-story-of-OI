#include <iostream>
#include <vector>
using namespace std;
long long int n, p[1000005], cnt[100005], ans = 0;
vector<int> son[1000005];
long long int dp[10005];
void solve(int id)
{
    for (int i = 1; i <= 5000; i++)
        dp[i] = 0;
    dp[0] = 1;
    int sum = 0;
    for (int i = 0; i < son[id].size(); i++)
    {
        sum += son[id][i];
        for (int j = sum; j >= son[id][i]; j--)
        {
            dp[j] = dp[j] | dp[j - son[id][i]];
        }
    }
    for (int i = sum / 2; i >= 1; i--)
    {
        if (dp[i] == 1)
        {
            ans += i * (sum - i);
            return;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = n; i >= 1; i--)
    {
        cnt[i]++;
        son[p[i]].push_back(cnt[i]);
        cnt[p[i]] += cnt[i];
    }
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    cout << ans << endl;
}