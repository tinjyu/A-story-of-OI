#include <iostream>
using namespace std;
int n, a[100005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        long long int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                cnt++;
            sum += a[i] - 1;
        }
        if (n == 1 || sum < cnt)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
}