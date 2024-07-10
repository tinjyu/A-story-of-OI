#include <iostream>
using namespace std;
int s, d, k;
string solve()
{
    cin >> s >> d >> k;
    if (s * 2 + d * 2 >= k + 1 && s + d * 2 >= k)
        return "YES";
    return "NO";
}
int main()
{
    freopen("cheeseburger_corollary_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}