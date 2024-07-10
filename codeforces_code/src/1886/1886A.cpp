#include <iostream>
using namespace std;
long long int n;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n <= 6)
        {
            cout << "NO" << endl;
        }
        else if (n % 3 != 0)
        {
            cout << "YES" << endl;
            cout << "1 2 " << n - 3 << endl;
        }
        else if (n != 9)
        {
            cout << "YES" << endl;
            cout << "1 4 " << n - 5 << endl;
        }
        else
            cout << "NO" << endl;
    }
}