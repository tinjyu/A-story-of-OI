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
#include <queue>
using namespace std;
long long int MOD=998244353;
long long int n,m,k,C;
string s;
long long int d[1000005],h[100005],c[1000004],dis[1000005],pos,cn;
vector<int> g[1000005];
set<int> val[1000005];
long long int ed[1000005];
long long int nd[1000005];
long long int ans=0;
long long int g1[100005],g2=0;
long long int f[1000005];
long long int cost[1000005];
int main(){
    cin>>n>>C;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i]>>d[i]>>h[i];
        cost[c[i]]=max(cost[c[i]],d[i]*h[i]);
    }
    for(int i=1;i<=C;i++)
    {
        long long int cnt=2;
        for(int j=i*2;j<=C;j+=i)
        {
            cost[j]=max(cost[j],cost[i]*cnt);
            cnt++;
        }
    }
    for(int i=1;i<=C;i++)
    {
        cost[i]=max(cost[i-1],cost[i]);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        long long int H,D;
        cin>>D>>H;
        long long int l=1,r=C,ans=-1;
        while(l<=r)
        {
            long long int mid=(l+r)/2;
            if(cost[mid]>H*D)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<" ";
    }
    return 0;
}