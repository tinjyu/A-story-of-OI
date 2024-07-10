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
long long int n,m,q,k,d,s,t,c;
long long int a[1000005],b[1000005],p[1000005],e[1000005],w[1000005];
long long int mi[1000005];
long long int tag[2000005],dis[2000005],dp[1000005][2];
long long int sum[2000005],cnt[2000005];
long long int ans=0;
vector<long long int> x[1000005],y[1000005];
int count(long long int x)
{
    int sum=0;
    while(x>0)
    {
        if(x%2==1)sum++;
        x/=2;
    }
    return sum;
}
void find(long long int x,long long int sum,int st)
{
    ans=min(ans,sum+count(x));
    long long int now=1;
    for(int i=1;i<=18;i++)
    {
        now*=i;
        if(x<now)break;
        if(i>=st)
        {
            find(x-now,sum+1,i+1);
        }
    }
    return ;
}
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans=999999999999;
        find(n,0,1);
        cout<<ans<<endl;
    }
    return 0;
}