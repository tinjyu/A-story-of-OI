#include <iostream>
using namespace std;
long long int n, k;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cout << i + 1000 << " ";
        cout << endl;
    }
}