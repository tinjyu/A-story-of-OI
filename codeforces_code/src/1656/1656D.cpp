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
        long long int k=1;
        while(n%2==0)n/=2,k*=2;
        if(n==1)cout<<"-1"<<endl;
        else cout<<min(n,k*2)<<endl;
    }
    return 0;
}