#include <iostream>
#include <string>
using namespace std;
int n;
string s;
int main()
{
    long long int ans = 0;

    cin >> s;
    for (int i = 13; i < s.length(); i++)
    {
        int flag = 0;
        for (int j = i; j >= i - 13; j--)
        {
            for (int k = j - 1; k >= i - 13; k--)
            {
                if (s[k] == s[j])
                    flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << i + 1 << endl;
            break;
        }
    }
}