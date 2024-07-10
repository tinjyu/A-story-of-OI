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
        if (n % 3 == 0)
            cout << "Second" << endl;
        else
            cout << "First" << endl;
    }
}