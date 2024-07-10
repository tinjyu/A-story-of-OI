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
using namespace std;
long long int MOD=998244353;
long long int n,m,q,k,d,w;
long long int a[1000005],b[1000005],c[1000005],p[1000005];
long long int mi[1000004];
long long int ti[1000005],dp[1000005];
string s;
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        long long int x,y;
        cin>>x>>y;
        long long int ans=y-x;
        for(long long int i=0;i<=y;i++)
        {
            ans=min(ans,i+((x+i) | y)-y+1);
        }
        for(long long int i=0;i<=y;i++)
        {
            ans=min(ans,i+(x | (y+i))-y-i+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}