#include <iostream>
#include <algorithm>
using namespace std;
long long int n, m, x[1000005];
long long int g[1000005];
string solve(int id)
{
    long long int p = 0;
    long long int sum = 0;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            p++;
            g[p] = i;
            n /= i;
            sum += i;
        }
    }
    if (n != 1)
        p++, g[p] = n, sum += n;
    cout << "Case #" << id << ": ";
    if (sum <= 41)
    {
        cout << 41 - sum + p << " ";
        for (int i = sum; i < 41; i++)
            cout << "1 ";
        for (int i = 1; i <= p; i++)
            cout << g[i] << " ";
        cout << endl;
    }
    else
        cout << "-1" << endl;
    return "";
}
int main()
{
    freopen("sum_41_chapter_1_input.txt", "r", stdin);
    freopen("sum_41_chapter_1_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
}