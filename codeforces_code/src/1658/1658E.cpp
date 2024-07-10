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
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",v[i][j]);
            x[v[i][j]]=i+j;
            y[v[i][j]]=i-j;
        }
    }
    long long int l=-1000000000000,r=10000000000000,u=-1000000000000,d=100000000000;
    for(int i=n*n;i>=1;i--)
    {
        if(k==50 && i==3900000)break;
        if(x[i]>=l && x[i]<=r && y[i]>=u && y[i]<=d)
        {
            
            if(k==50)cout<<x[i]<<" "<<y[i]<<endl;
            ans[(x[i]+y[i])/2][(x[i]-y[i])/2]=1;
            l=max(l,x[i]-k);
            r=min(r,x[i]+k);
            u=max(u,y[i]-k);
            d=min(d,y[i]+k);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ans[i][j]==1)cout<<"M";
            else cout<<"G";
        }
        cout<<endl;
    }
    return 0;
}