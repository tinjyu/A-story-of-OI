#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
long long int n, ans = 0;
long long int num = 0, a[100005];
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
    num++;
    a[num] = size;
    if (size <= 100000)
    {
        ans += size;
    }
    return size;
}
int main()
{
    getline(cin, s);
    long long int temp = dfs();
    temp -= 40000000;
    sort(a + 1, a + num + 1);
    for (int i = 1; i <= num; i++)
    {
        if (a[i] >= temp)
        {
            cout << a[i] << endl;
            break;
        }
    }
}