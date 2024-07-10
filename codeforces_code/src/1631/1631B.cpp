/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <ctime>
#include <queue>
using namespace std;
long long int MOD=998244353;
long long int n,m,q,k,d,w;
long long int a[1000005],b[1000005],c[1000005],p[1000005];
long long int mi[1000004];
long long int ti[1000005],dp[1000005];
string s;
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        long long int pre=n-1,ans=0;
        for(int i=n-1;i>=1;i--)
        {
            if(i<=pre && a[i]!=a[n])
            {
                pre=i-(n-i);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}