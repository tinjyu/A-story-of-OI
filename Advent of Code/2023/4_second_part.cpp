#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long int a[1005], b[10005];
long long int num[1005];
int main()
{
    long long int ans = 0;
    for (int i = 1; i <= 201; i++)
        num[i] = 1;
    for (int i = 1; i <= 201; i++)
    {
        string s;
        cin >> s;
        cin >> s;
        for (int i = 1; i <= 10; i++)
        {
            cin >> a[i];
        }
        cin >> s;
        for (int i = 1; i <= 25; i++)
        {
            cin >> b[i];
        }
        long long int cnt = 0;
        for (int i = 1; i <= 25; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                if (b[i] == a[j])
                {
                    cnt++;
                    break;
                }
            }
        }
        for (int j = i + 1; j <= i + cnt; j++)
            num[j] += num[i];
        ans += num[i];
    }
    cout << ans << endl;
}