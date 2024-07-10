#include <iostream>
using namespace std;
long long int n, m;
string x, s;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        cin >> x >> s;
        long long int p = 0, flag = 0;
        while (n <= 100)
        {
            if (x.find(s) != -1)
            {
                flag = 1;
                break;
            }
            p++;
            x = x + x;
            n *= 2;
        }
        if (flag == 0)
            cout << "-1" << endl;
        else
            cout << p << endl;
    }
}