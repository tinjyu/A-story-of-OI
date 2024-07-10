#include <iostream>
using namespace std;
int tag[100005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            tag[i] = 0;
        }
        for (int i = n; i >= 1; i--)
        {
            int temp = i;
            if (tag[temp] == 1)
                continue;
            cout << temp << " ";
            while (temp % 2 == 0)
            {
                cout << temp / 2 << " ";
                tag[temp / 2] = 1;
                temp /= 2;
            }
        }
        cout << endl;
    }
}