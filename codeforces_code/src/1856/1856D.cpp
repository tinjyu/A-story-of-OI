#include <iostream>
using namespace std;
long long int n;
int find(int l, int r)
{
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    int le = find(l, mid), ri = find(mid + 1, r);
    long long int val1, val2;
    if (ri - 1 != le)
    {
        cout << "? " << le << " " << ri - 1 << endl;
        cin >> val1;
    }
    else
        val1 = 0;
    cout << "? " << le << " " << ri << endl;
    cin >> val2;
    if (val1 == val2)
        return ri;
    else
        return le;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << "! " << find(1, n) << endl;
    }
}