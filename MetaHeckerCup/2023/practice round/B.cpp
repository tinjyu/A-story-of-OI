#include <iostream>
using namespace std;
long long int a, b, r, c;
string solve()
{
    cin >> r >> c >> a >> b;
    if (r > c)
        return "YES";
    else
        return "NO";
}
int main()
{
    freopen("dim_sum_delivery_input.txt", "r", stdin);
    freopen("dim_sum_delivery_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}