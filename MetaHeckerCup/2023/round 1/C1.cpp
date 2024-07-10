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
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> x[i];
        tag[x[i]]++;
        tag[x[i]] %= 2;
    }
    long long int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tag[i] == 1)
        {
            for (int j = i; j <= n; j += i)
            {
                if (s[j] == '1')
                    s[j] = '0';
                else
                    s[j] = '1';
            }
        }
        if (s[i] == '1')
        {
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
    return ans;
}
int main()
{
    freopen("back_in_black_chapter_1_input.txt", "r", stdin);
    freopen("back_in_black_chapter_1_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}