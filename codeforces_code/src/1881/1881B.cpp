#include <iostream>
using namespace std;
long long int n, m, a, b, c;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;
        int flag = 0;
        for (int i = 3; i <= 6; i++)
        {
            if ((a + b + c) % i != 0)
                continue;
            int sum = (a + b + c) / i;
            if (a % sum != 0 || b % sum != 0 || c % sum != 0)
                continue;
            flag = 1;
        }
        if (flag == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}