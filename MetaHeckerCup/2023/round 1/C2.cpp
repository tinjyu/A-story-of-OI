#include <iostream>
#include <algorithm>
using namespace std;
long long int n, q, x[4000005], tag[4000005];
string s;
long long int solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        tag[i] = 0;
    cin >> s;
    s = " " + s;
    long long int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            tag[i] = 1;
            ans++;
            for (int j = i; j <= n; j += i)
            {
                if (s[j] == '1')
                    s[j] = '0';
                else
                    s[j] = '1';
            }
        }
    }
    cin >> q;
    long long int sum = 0;
    for (int i = 1; i <= q; i++)
    {
        cin >> x[i];
        if (tag[x[i]] == 1)
        {
            ans--;
            tag[x[i]]--;
        }
        else
        {
            ans++;
            tag[x[i]]++;
        }
        sum += ans;
    }
    return sum;
}
int main()
{
    freopen("back_in_black_chapter_2_input.txt", "r", stdin);
    freopen("back_in_black_chapter_2_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}