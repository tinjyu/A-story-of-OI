#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        if (s == "()")
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            bool flag = 0;
            for (int i = 0; i < s.length() - 1; i++)
            {
                if (s[i] == s[i + 1])
                    flag = 1;
            }
            if (flag == 1)
            {
                for (int i = 0; i < s.length(); i++)
                    cout << "()";
            }
            else
            {
                for (int i = 0; i < s.length(); i++)
                    cout << "(";
                for (int i = 0; i < s.length(); i++)
                    cout << ")";
            }
            cout << endl;
        }
    }
}