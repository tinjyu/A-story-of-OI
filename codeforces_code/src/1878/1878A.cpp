#include <iostream>
using namespace std;
long long int n, k;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int flag = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            if (temp == k)
                flag = 1;
        }
        if (flag == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}