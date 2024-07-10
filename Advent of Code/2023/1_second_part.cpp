#include <iostream>
using namespace std;
string a[100] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string b[100] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
string s;
int check(long long int st)
{
    for (int i = 1; i <= 9; i++)
    {
        if (st + a[i].length() > s.length())
        {
            continue;
        }
        int flag = 0;
        for (int j = 0; j < a[i].length(); j++)
        {
            if (a[i][j] != s[st + j])
                flag = 1;
        }
        if (flag == 0)
            return i;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (st + b[i].length() > s.length())
        {
            continue;
        }
        int flag = 0;
        for (int j = 0; j < b[i].length(); j++)
        {
            if (b[i][j] != s[st + j])
                flag = 1;
        }
        if (flag == 0)
            return i;
    }
    return -1;
}
int main()
{
    long long int ans = 0;
    for (int i = 1; i <= 1000; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            int temp = check(j);
            if (temp == -1)
                continue;
            ans += temp * 10;
            break;
        }
        for (int j = s.length(); j >= 0; j--)
        {
            int temp = check(j);
            if (temp == -1)
                continue;
            ans += temp;
            break;
        }
    }
    cout << ans << endl;
}