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
long long int n,m,q;
long long int a[200005],id[1000005],b[1000005],c[1000005];
long long int tree[1000005];
string s,t;
map<int,int> mp;
long long int cnt[1000005];
long long int mi,p;
long long int pre[1004];
long long int dp[10000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {    
        cin>>n;
        if(n%2==1)
        {
            cout<<"0"<<endl;
            continue;
        }
        long long int ans=1;
        for(int i=1;i<=n/2;i++)
        {
            ans*=i;
            ans%=MOD;
        }
        cout<<ans*ans%MOD<<endl;
    }
    return 0;
}