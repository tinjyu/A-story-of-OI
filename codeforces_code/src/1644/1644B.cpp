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
long long int n,m,q,k,d,t,c;
long long int a[1000005],b[1000005],p[1000005],e[1000005],w[1000005];
long long int mi[1000005];
long long int tag[2000005],dis[2000005],dp[1000005][2];
long long int sum[2000005],cnt[2000005];
long long int ans=0;
string s;
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n==3)
        {
            cout<<"3 2 1"<<endl;
            cout<<"3 1 2"<<endl;
            cout<<"1 3 2"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            int now=n-i+1;
            for(int j=1;j<=n;j++)
            {
                cout<<now<<" ";
                now--;
                if(now==0)now=n;
            }
            cout<<endl;
        }
    }
    return 0;
}