#include <iostream>
using namespace std;
double p;
int n, l, r;
double quick(double temp, int num)
{
    num--;
    double x = temp;
    while (num > 0)
    {
        if (num % 2 == 1)
            temp *= x;
        num /= 2;
        x *= x;
    }
    return temp;
}
int main()
{
    cin >> n >> p >> l >> r;
    double ans = (r - l + 1) * p;
    printf("%.6lf", ans);
}