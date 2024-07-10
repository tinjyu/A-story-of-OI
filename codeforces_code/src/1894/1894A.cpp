#include <iostream>
using namespace std;
long long int n;
string s;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cin >> s;
        cout << s[n - 1] << endl;
    }
}