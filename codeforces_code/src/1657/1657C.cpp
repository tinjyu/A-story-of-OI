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
        cin>>s;
        long long int cnt=0,pre=-1;
        long long int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')')cnt--;
            else cnt++;
            if(cnt<0)break;
            if(cnt==0)ans++;

        }
        cout<<ans<<" "<<n-pre-1<<endl;
    }
    return 0;
}