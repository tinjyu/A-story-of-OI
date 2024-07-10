#include <iostream>
#include <map>
using namespace std;
long long int a[1000005], n;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        map<long long int, int> mp;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int j = 2; j * j <= a[i]; j++)
            {
                while (a[i] % j == 0)
                {
                    mp[j]++;
                    a[i] /= j;
                }
            }
            if (a[i] != 1)
            {
                mp[a[i]]++;
            }
        }
        int flag = 0;
        for (auto &m : mp)
        {
            if (m.second % n != 0)
                flag = 1;
        }
        if (flag == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}