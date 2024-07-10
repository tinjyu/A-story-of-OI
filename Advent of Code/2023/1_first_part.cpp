#include <iostream>
using namespace std;
int main()
{
    long long int ans = 0;
    for (int i = 1; i <= 1000; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] <= '9' && s[j] >= '0')
            {
                ans += (s[j] - '0') * 10;
                break;
            }
        }
        for (int j = s.length(); j >= 0; j--)
        {
            if (s[j] <= '9' && s[j] >= '0')
            {
                ans += (s[j] - '0');
                break;
            }
        }
    }
    cout << ans << endl;
}