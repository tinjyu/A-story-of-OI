#include <iostream>
using namespace std;
long long int n, m, k;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        long long int cnt = m / n - (m >= n);
        if (k == 1)
        {
            cout << "1" << endl;
        }
        else if (k == 2)
        {
            cout << min(n + cnt, m) << endl;
        }
        else if (k == 3)
        {
            cout << max((long long int)0, m - n - cnt) << endl;
        }
        else
            cout << "0" << endl;
    }
}