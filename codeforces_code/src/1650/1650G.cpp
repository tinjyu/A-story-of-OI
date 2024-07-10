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
        cin>>n>>m>>s>>t;
        for(int i=1;i<=n;i++)
        {
            nxt[i].clear();
            tag[i]=0;
            dis[i]=1e18;
            dp[i][0]=0;
            dp[i][1]=0;
        }
        dp[s][0]=1;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            nxt[u].push_back(v);
            nxt[v].push_back(u);
        }
        dis[s]=0;
        queue<pair<int,int>> q;
        tag[s]=1;
        q.push(make_pair(s,0));
        long long int mi=1e18;
        long long int ans=0;
        while(q.empty()==0)
        {
            long long int u=(q.front()).first,len=(q.front()).second,cnt=dp[u][len-dis[u]];
            //cout<<u<<" "<<len<<" "<<dis[u]<<" "<<cnt<<endl;
            q.pop();
            if(u==t)
            {
                if(mi==1e18)mi=len;
                if(len<=mi+1)
                {
                    ans+=cnt;
                    if(ans>=MOD)ans-=MOD;
                }
            }
            if(len>mi+1)break;
            for(int v:nxt[u])
            {
                if(len<=dis[v])
                {
                    dis[v]=min(dis[v],len+1);
                    dp[v][len+1-dis[v]]+=cnt;
                    if(dp[v][len+1-dis[v]]>=MOD)dp[v][len+1-dis[v]]-=MOD;
                    if(tag[v]==0 || (tag[v]==1 && dis[v]==len))
                    {
                        tag[v]++;
                        q.push(make_pair(v,len+1));
                    }
                }
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;
}