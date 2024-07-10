#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int ti = 0, ans = 0, x = 1;
    for (int i = 1; i <= 139; i++)
    {
        string s;
        cin >> s;
        if (s == "noop")
        {
            ti++;
            if (ti % 40 == 20)
                ans += x * ti;
            continue;
        }
        int num = 0;
        cin >> num;
        ti++;
        if (ti % 40 == 20)
            ans += x * ti;
        ti++;
        if (ti % 40 == 20)
            ans += x * ti;
        x += num;
    }
    cout << ans << endl;
}