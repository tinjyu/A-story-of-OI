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
        long long int x,y;
        cin>>x>>y;
        if(x==0 && y==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        long long int tmp=x*x+y*y;
        long long int c=0;
        for(int i=1;i<=100;i++)
        {
            if(i*i==tmp)c=1;
        }
        if(c==1)cout<<1<<endl;
        else cout<<"2"<<endl;
    }
    return 0;
}