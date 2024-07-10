#include <iostream>
#include <string>
using namespace std;
int main()
{
    long long int ans = 0;
    for (int i = 1; i <= 1000; i++)
    {
        int a, b, c, d;
        scanf("%d-%d,%d-%d", &a, &b, &c, &d);
        ans++;
        if (b < c || a > d)
            ans--;
    }
    cout << ans << endl;
}