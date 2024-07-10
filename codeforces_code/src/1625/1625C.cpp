/*

kaaa_kawai

*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
#include <ctime>

using namespace std;
long long int MOD=998244353;
long long int n,m,l,k;
long long int a[1000005];
long long int map[1000005][2],road[1000005],deg[100005],ans[1000005];
long long int d[1000005];
long long int dp[505][505];
pair<int,int> pa[1000005];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    //cin>>T;
    T=1;
    while(T--)
    {
        cin>>n>>l>>k;
        for(int i=1;i<=n;i++)cin>>d[i];
        for(int i=1;i<=n;i++)cin>>a[i];
        d[n+1]=l;
        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=n+1;j++)dp[i][j]=1e18;
        }
        dp[1][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                for(int pos=i+1;pos<=n+1;pos++)
                {
                    if(pos-i-1+j>k)break;
                    dp[pos][pos-i-1+j]=min(dp[pos][pos-i-1+j],dp[i][j]+a[i]*(d[pos]-d[i]));
                }
            }
        }
        long long int ans=1e18;
        for(int i=0;i<=k;i++)ans=min(ans,dp[n+1][i]);
        cout<<ans<<endl;
    }
    return 0;
}
