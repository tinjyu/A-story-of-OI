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
long long int n,m,q,k,d,s,t;
long long int a[1000005],b[1000005],p[1000005],e[1000005],x[1000005],ans[1000005],w[1000005];
long long int mi[1000005];
long long int tag[1000005],dis[1000005],dp[1000005][2];
vector<int> task[1000005];
vector<int> nxt[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        long long int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        long long int ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,a[i]-(sum-a[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}