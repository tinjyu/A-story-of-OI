#include <iostream>
using namespace std;

long long int x, k;

long long int sum(long long int n)
{
    long long int cnt = 0;
    while (n > 0)
    {
        cnt += n % 10;
        n /= 10;
    }
    return cnt;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> x >> k;
        for (int i = x; i <= x + 20; i++)
        {
            if (sum(i) % k == 0)
            {
                cout << i << endl;
                break;
            }
        }
    }
}