#include <iostream>
using namespace std;
int n;
int stack[100005];
int per[100005], tmpper[100005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        long long int ans = 0;
        for (int i = 1; i <= n * n; i++)
        {
            long long int cnt = -i;
            bool flag = 0;
            int top = 0, now = 1;
            for (int j = n; j >= 1; j--)
            {
                while (now <= n && now * j <= i)
                {
                    top++;
                    stack[top] = now;
                    now++;
                }
                if (top == 0)
                {
                    flag = 1;
                    break;
                }
                tmpper[j] = stack[top];
                cnt += j * stack[top];
                top--;
            }
            if (flag == 0)
            {
                if (cnt > ans)
                {
                    for (int j = 1; j <= n; j++)
                        per[j] = tmpper[j];
                }
                ans = max(ans, cnt);
            }
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++)
            cout << per[i] << " ";
        cout << endl;
    }
}