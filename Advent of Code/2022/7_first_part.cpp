#include <iostream>
#include <string>
using namespace std;
long long int n, ans = 0;
string s;
long long int dfs()
{
    getline(cin, s);
    getline(cin, s);
    long long int size = 0;
    while (s[0] != '$')
    {
        long long int cnt = 0, p = 0;
        while (s[p] <= '9' && s[p] >= '0')
        {
            cnt *= 10;
            cnt += s[p] - '0';
            p++;
        }
        size += cnt;
        getline(cin, s);
    }
    while (s[5] != '.')
    {
        size += dfs();
        getline(cin, s);
    }
    cout << "size"
         << " " << size << endl;
    if (size <= 100000)
    {
        cout << size << endl;
        ans += size;
        cout << ans << endl;
    }
    return size;
}
int main()
{
    getline(cin, s);
    dfs();
    cout << ans << endl;
}