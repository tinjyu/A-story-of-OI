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
#include <map>

using namespace std;
long long int MOD=998244353;
long long int n,m,q,k;
long long int a[200005],id[1000005],b[1000005],c[1000005];
long long int tree[1000005];
string s,t;
map<int,int> mp;
long long int cnt[1000005];
long long int mi,p;
long long int pre[1004];
long long int dp[4000005],x[4000005],y[4000005];
long long int ans[2005][2005],v[2005][2005];
long long int sum[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+a[i];
        }
        long long int count=0;
        for(int i=1;i<n;i++)
        {
            count+=a[i];
        }
        if(count+a[n]*(n-1)<0)
        {
            cout<<"INF"<<endl;
            continue;
        }
        count=0;
        for(int i=2;i<=n;i++)
        {
            count+=a[i];
        }
        if(count+a[1]*(n-1)>0)
        {
            cout<<"INF"<<endl;
            continue;
        }
        long long int ans=-2e18;
        for(int i=1;i<=n;i++)
        {
            long long int t=-a[i];
            count=0;
            if(i!=1)
            {
                count+=(a[n]+t)*(sum[i-1]+(i-1)*t);
            }
            if(i!=n)
            {
                count+=(a[1]+t)*(sum[n]-sum[i]+(n-i)*t);
            }
            //cout<<i<<" "<<count<<" "<<sum[i-1]<<" "<<sum[n]-sum[i]<<endl;
            count-=t*t*(n-1);
            count-=(a[1]+t)*(a[n]+t);
            ans=max(ans,count);
        }
        cout<<ans<<endl;
    }
    return 0;
}