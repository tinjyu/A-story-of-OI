/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;
long long int MOD=998244353;
long long int n,m,k;
long long int a[1000005],id[1000005],b[1000005];
long long int cnt[30][30],sum[1000005];
long long int dp[1000005];
long long int f[1000005],c;
vector<long long int> mp[1000005];
string s;
pair<long long int,long long int> pa[1000005];


int main(){
    int T;
    cin>>T;
    while(T--)
    {
        long long int x,y;
        cin>>n>>x>>y;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+a[i];
        }
        long long int ans=1000000000000000000;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,(sum[n]-sum[i]-a[i]*(n-i))*y+a[i]*(x+y));
           // cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
}
