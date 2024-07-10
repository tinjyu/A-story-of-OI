/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;
long long int MOD=998244353;
long long int n,m,k;
long long int a[1000005],id[1000005],b[1000005],c[1000005];
long long int cnt[30][30],sum[1000005];
long long int dp[1000005];
long long int f[1000005];
vector<long long int> mp[1000005];
string s;
pair<long long int,long long int> pa[1000005];
long long int last[1000005];

int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        long long int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
            sum+=c[i];
        }
        sum/=n;
        for(int i=n-sum+1;i<=n;i++)
        {
            last[i]=n+1;
        }
        int now=n-sum;
        for(int i=n;i>=1;i--)
        {
            if(i+max((long long int)0,last[i]-i-1)==c[i])
            {
                a[i]=1;
            }
            else
            {
                a[i]=0;
                last[now]=i;
                now--;
            }
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;

    }
}
