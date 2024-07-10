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
    mi[1]=0;
    for(int i=2;i<=1000;i++)mi[i]=99999999999;
    for(int i=1;i<=1000;i++)
    {
        //cout<<i<<" "<<mi[i]<<endl;
        for(int j=1;j<=i;j++)
        {
            mi[i+i/j]=min(mi[i+i/j],mi[i]+1);
        }
    }
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            ti[i]=mi[b[i]];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
        }
        long long int ma=0,ans=0;
        for(int i=1;i<=12*n;i++)
        {
            dp[i]=-1e18;
        }
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=ma;j>=0;j--)
            {
                dp[j+ti[i]]=max(dp[j+ti[i]],dp[j]+c[i]);
            }
            ma+=ti[i];
        }
        ma=min(ma,k);
        for(int i=0;i<=ma;i++)ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
    return 0;
}