#include <iostream>
using namespace std;
long long int n;
string s;
long long int a[100005], cnt[100005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= 100; i++)
            cnt[i] = 0;
        long long int count = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
            if (cnt[a[i]] == 2)
                count++;
        }
        if (count < 2)
        {
            cout << "-1" << endl;
            continue;
        }
        long long int temp1 = 0, temp2 = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (temp1 == 0 && cnt[i] >= 2)
                temp1 = i;
            else if (temp2 == 0 && cnt[i] >= 2)
                temp2 = i;
        }
        long long int tag1 = 0, tag2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == temp1)
            {
                if (tag1 == 0)
                    cout << "1 ";
                else
                    cout << "2 ";
                tag1 = 1;
            }
            else if (a[i] == temp2)
            {
                if (tag2 == 0)
                    cout << "1 ";
                else
                    cout << "3 ";
                tag2 = 1;
            }
            else
                cout << "3 ";
        }
        cout << endl;
    }
}