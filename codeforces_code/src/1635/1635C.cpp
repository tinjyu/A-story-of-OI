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
        cin>>n;
        int c=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i!=1)
            {
                if(a[i]<a[i-1])c=1;
            }
        }
        if(c==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(a[n]<a[n-1])
        {
            cout<<-1<<endl;
            continue;
        }
        if(a[n]<0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        cout<<n-2<<endl;
        for(int i=1;i<=n-2;i++)
        {
            cout<<i<<" "<<n-1<<" "<<n<<endl;
        }
    }
    return 0;
}