#include <iostream>
using namespace std;
long long int a[10005], b[10005], c[10005], num[100005];
int main()
{
    int n = 20;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }

    while (true)
    {
        int cnt = 1;
        cin >> a[cnt] >> b[cnt] >> c[cnt];
        while (a[cnt] != 0 || b[cnt] != 0 || c[cnt] != 0)
        {
            cnt++;
            cin >> a[cnt] >> b[cnt] >> c[cnt];
        }
        cnt--;
        long long int mi = 999999999999999;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= cnt; j++)
            {
                if (num[i] <= b[j] + c[j] - 1 && num[i] >= b[j])
                {
                    num[i] += a[j] - b[j];
                    break;
                }
            }
            mi = min(mi, num[i]);
            cout << num[i] << " ";
        }

        cout << mi << endl;
    }
}