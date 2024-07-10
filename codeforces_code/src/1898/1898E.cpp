#include <iostream>
using namespace std;
long long int n, m;
string s, t;
long long int q[200005][30];
long long int num[30], p[30];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        cin >> s >> t;
        for (int i = 0; i <= 26; i++)
        {
            num[i] = 0;
            p[i] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            int id = s[i] - 'a';
            num[id]++;
            q[num[id]][id] = i;
        }
        int flag = 0;
        for (int i = 0; i < m; i++)
        {
            int id = t[i] - 'a';
            if (p[id] > num[id])
            {
                flag = 1;
                break;
            }
            for (int j = 0; j < id; j++)
            {
                while (p[j] <= num[j] && q[p[j]][j] < q[p[id]][id])
                {
                    p[j]++;
                }
            }
            p[id]++;
        }
        if (flag == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}