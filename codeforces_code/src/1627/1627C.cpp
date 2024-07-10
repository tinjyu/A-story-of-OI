/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
#include <ctime>

using namespace std;
long long int MOD=998244353;
long long int n,m,k;
long long int map[1000005][2],road[1000005],deg[100005],ans[1000005];
int find(int u,int fa,int val)
{
    int g=road[u];
    while(g!=-1)
    {
        int v=map[g][0];
        if(v!=fa)
        {
            ans[g/2]=val;
            find(v,u,5-val);
        }
        g=map[g][1];
    }
    return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            road[i]=-1;
            deg[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
            map[i*2][0]=v;
            map[i*2][1]=road[u];
            road[u]=i*2;
            map[i*2+1][0]=u;
            map[i*2+1][1]=road[v];
            road[v]=i*2+1;
        }
        int ok=0;
        for(int i=1;i<=n;i++)
        {
            if(deg[i]>2)ok=1;
        }
        if(ok==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(deg[i]==1)
            {
                find(i,0,3);
            }
        }
        for(int i=1;i<n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
