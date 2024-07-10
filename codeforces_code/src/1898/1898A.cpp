#include <iostream>
using namespace std;
long long int n, k;
string s;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
                cnt++;
        }
        if (cnt == k)
        {
            cout << 0 << endl;
            continue;
        }
        int tempcnt = 0;
        cout << "1" << endl;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
                tempcnt++;
            if (cnt - tempcnt + i + 1 == k)
            {
                cout << i + 1 << " "
                     << "B" << endl;
                break;
            }
            if (cnt - tempcnt == k)
            {
                cout << i + 1 << " "
                     << "A" << endl;
                break;
            }
        }
    }
}