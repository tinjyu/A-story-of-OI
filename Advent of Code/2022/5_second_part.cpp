#include <iostream>
#include <string>
using namespace std;
char stack[15][100];
int num[105];
int main()
{
    long long int ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        string s;
        cin >> s;
        num[i] = s.length();
        for (int j = 1; j <= num[i]; j++)
        {
            stack[i][j] = s[j - 1];
        }
    }
    for (int i = 1; i <= 504; i++)
    {
        string s;
        int a, b, c;
        cin >> s >> a >> s >> b >> s >> c;
        num[b] -= a;
        for (int j = 1; j <= a; j++)
        {
            stack[c][num[c] + j] = stack[b][num[b] + j];
        }
        num[c] += a;
        for (int j = 1; j <= 9; j++)
            cout << stack[j][num[j]];
        cout << endl;
    }
    for (int i = 1; i <= 9; i++)
        cout << stack[i][num[i]];
}