#include <iostream>
using namespace std;
long long int n;
string s;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cin >> s;
        int p = n - 1;
        long long int ans = 0, flag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            while (p >= 0 && s[p] == '1')
                p--;
            if (p == -1)
            {
                cout << "-1 ";
                continue;
            }
            if (s[i] == '1')
            {
                ans += i - p;
                swap(s[i], s[p]);
                p--;
            }
            else if (i == p)
                p--;
            cout << ans << " ";
        }
        cout << endl;
    }
}