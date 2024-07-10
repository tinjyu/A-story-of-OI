#include <iostream>
#include <map>
using namespace std;

map<string, pair<string, string>> mp;
long long int type[1005], cost[100005];
long long int cont[10005];
string start[100005];
int num = 0;
string step;

long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int n = 754;
    cin >> step;
    for (int i = 1; i <= n; i++)
    {
        string temp, st;
        cin >> st;
        pair<string, string> pa = {"", ""};
        cin >> temp;
        cin >> temp;
        pa.first = temp.substr(1, 3);
        cin >> temp;
        pa.second = temp.substr(0, 3);
        mp[st] = pa;
        cout << pa.first << " " << pa.second << endl;
        if (st[2] == 'A')
        {
            num++;
            start[num] = st;
        }
    }
    int flag = 0, ans = 0;
    for (int j = 1; j <= num; j++)
    {
        flag = 0, ans = 0;
        while (true)
        {
            for (int i = 0; i < step.length(); i++)
            {
                if (step[i] == 'L')
                    start[j] = mp[start[j]].first;
                else
                    start[j] = mp[start[j]].second;

                ans++;
                int cnt = 0;
                if (start[j][2] == 'Z')
                {
                    cont[j] = ans;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
    }
    for (int i = 1; i < num; i++)
    {
        cont[i + 1] = cont[i] * cont[i + 1] / gcd(cont[i], cont[i + 1]);
    }
    cout << cont[num] << endl;
}