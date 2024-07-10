#include <iostream>
using namespace std;
int main()
{
    int T, a, b, c;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;
        a += c / 2 + c % 2;
        b += c / 2;
        if (a > b)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
}