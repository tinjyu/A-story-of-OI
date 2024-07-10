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
#include <map>
using namespace std;
long long int MOD=1000000007;
long long int n,m,q,k,d,t,c,x;
long long int a[1000005],b[1000005],p[1000005],e[1000005],w[1000005];
long long int mi[1000005];
long long int tag[2000005],dis[2000005],dp[1000005][2];
long long int sum[2000005],cnt[2000005];
long long int mx[100005];
long long int ans=0;
string s;
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>x;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mx[i]=-1e18;
        }
        for(int i=1;i<=n;i++)
        {
            long long int sum=0;
            for(int j=i;j<=n;j++)
            {
                sum+=a[j];
                mx[j-i+1]=max(mx[j-i+1],sum);
            }
        }
        for(int i=0;i<=n;i++)
        {
            long long int ans=0;
            for(int j=1;j<=n;j++)
            {
                if(j<=i)ans=max(ans,mx[j]+j*x);
                else ans=max(ans,mx[j]+x*i);
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}