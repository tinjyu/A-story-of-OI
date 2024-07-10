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
long long int a[1000005],id[1000005],b[1000005];
long long int cnt[30][30],sum[1000005];
long long int dp[1000005];
long long int f[1000005],c;
vector<long long int> mp[1000005];
string s;
pair<long long int,long long int> pa[1000005];


int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        long long int tmp=k;
        for(int i=1;i<=n;i++)
        {
            char c;
            cin>>c;
            a[i]=c-'0';
            b[i]=0;
        }
        int sum=0;
        for(int i=1;i<n;i++)
        {
            if((a[i]+tmp)%2==1)continue;
            else 
            {
                if(k!=0)
                {
                    k--;
                    b[i]=1;
                }
            }
        }
        b[n]=k;
        for(int i=1;i<=n;i++)
        {
            cout<<(a[i]+tmp-b[i])%2;
        }
        cout<<endl;
        for(int i=1;i<=n;i++)cout<<b[i]<<" ";
        cout<<endl;
    }
}
