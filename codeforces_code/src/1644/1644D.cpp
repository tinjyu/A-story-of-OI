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
long long int MOD=998244353;
long long int n,m,q,k,d,c;
long long int ct[1000005],a[1000005],b[1000005],p[1000005],e[1000005],w[1000005];
long long int mi[1000005],x[1000005],y[1000005];
long long int dis[2000005],dp[1000005][2];
long long int sum[2000005],cnt[2000005];
long long int mx[100005];
long long int ans=0;
long long int sg[5000005];
long long int tag1[1000005],tag2[1000005];
vector<int> v[1005];
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k>>q;
        for(int i=1;i<=q;i++)
        {
            cin>>x[i]>>y[i];
        }
        int cnt1=0,cnt2=0,cnt=0;
        for(int i=q;i>=1;i--)
        {
            if(tag1[x[i]]==1 && tag2[y[i]]==1)continue;
            if(tag1[x[i]]==0)
            {
                tag1[x[i]]=1;
                cnt1++;
            }
            if(tag2[y[i]]==0)
            {
                tag2[y[i]]=1;
                cnt2++;
            }
            cnt++;
            if(cnt1==n || cnt2==m)break;
        }
        long long int ans=1;
        for(int i=1;i<=cnt;i++)
        {
            ans*=k;
            ans%=MOD;
        }
        for(int i=1;i<=q;i++)
        {
            tag1[x[i]]=0;
            tag2[y[i]]=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}