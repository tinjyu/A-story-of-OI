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
long long int sum[1000005],a[1000005],b[1000005],p[1000005],e[1000005],ans[1000005],w[1000005];
long long int mi[1000005];
long long int tag[1000005],dis[1000005],dp[1000005][2];
vector<long long int> x[1000005],y[1000005];
int main(){
    int T;
    //cin>>T;
    T=1;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=100000;i++)x[i].clear(),y[i].clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int tmp;
                cin>>tmp;
                x[tmp].push_back(i);
                y[tmp].push_back(j);
            }
        }
        long long int ans=0;
        for(int i=1;i<=100000;i++)
        {
            sort(x[i].begin(),x[i].end());
            sort(y[i].begin(),y[i].end());
            for(int j=0;j<x[i].size();j++)
            {
                sum[j+1]=sum[j]+x[i][j];
            }
            for(int j=1;j<=x[i].size();j++)
            {
                ans+=sum[x[i].size()]-sum[j]-x[i][j-1]*(x[i].size()-j)+x[i][j-1]*(j-1)-sum[j-1];
            }
            for(int j=0;j<y[i].size();j++)
            {
                sum[j+1]=sum[j]+y[i][j];
            }
            for(int j=1;j<=y[i].size();j++)
            {
                ans+=sum[y[i].size()]-sum[j]-y[i][j-1]*(x[i].size()-j)+y[i][j-1]*(j-1)-sum[j-1];
            }
            //cout<<ans<<endl;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}