#include <iostream>
using namespace std;
long long int n, a[1000005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int id = 0;
        long long int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= 0)
            {
                if (id == 0)
                    id = i;
                sum += a[i];
            }
        }
        if (id == 2)
        {
            cout << sum - min(a[2], -a[1]) << endl;
        }
        else
        {
            cout << sum << endl;
        }
    }
}