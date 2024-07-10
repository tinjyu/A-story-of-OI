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
        long long int sum = 0;
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        cout << -sum << endl;
    }
}