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
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        long long int mi=999999999999,p,q,mx=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<mi)
            {
                mi=a[i];
                p=i;
            }
            if(a[i]>mx)
            {
                mx=a[i];
                q=i;
            }
        }
        cout<<p<<" "<<q<<endl;
    }
    return 0;
}