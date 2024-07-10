#include <iostream>
using namespace std;
long long int n, k, x;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> x;
        long long int mi = (1 + k) * k / 2, ma = (n + n - k + 1) * k / 2;
        if (mi <= x && x <= ma)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}