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


string w;
long long int MOD=1000000007;
long long int n,m,q,z,k,b[1000005];
long long int road[1000005],u[1000005];
long long int dp[1000005],ans;

long long int cunt[1000005];

long long int map[1000005][2];


long long int tag[1000005];

long long int cnt=0;
long long int deg[1000005];
long long int f[200005][21],d[1000005];
pair<long long int,long long int> pa[1000005];

int find(int x,int fa)
{
    cnt++;
    f[x][0]=fa;
    d[x]=d[fa]+1;
    long long int g=road[x];
    while(g!=-1)
    {
        int now=map[g][0];
        if(now!=fa)
        {
            find(now,x);
        }
        g=map[g][1];
    }
    return 0;
}

int lca(int u,int v)
{
    
    if(d[u]<d[v])swap(u,v);
    //cout<<u<<" "<<v<<" "<<d[u]-d[v]<<endl;
    int tmp=d[u]-d[v],pp=0;
    while(tmp>0)
    {
        if(tmp%2==1)u=f[u][pp];
        pp++;
        tmp/=2;
    }
    //cout<<d[u]<<" "<<d[v]<<endl;
    if(u==v)return u;
    for(int i=20;i>=0;i--)
    {
        //cout<<i<<" "<<f[u][i]<<" "<<f[v][i]<<endl;
        if(f[u][i]==f[v][i])continue;
        u=f[u][i];
        v=f[v][i];
    }
    //cout<<" "<<u<<" "<<v<<endl;
    return f[u][0];
}

int main(){
    int T;
    cin>>n;
    for(int i=1;i<=n;i++)road[i]=-1;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        map[i*2][0]=v;
        map[i*2][1]=road[u];
        road[u]=i*2;
        map[i*2+1][0]=u;
        map[i*2+1][1]=road[v];
        road[v]=i*2+1;
    }
    find(1,0); 
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[j][i]=f[f[j][i-1]][i-1];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>b[i];
            pa[i].second=b[i];
            pa[i].first=-d[b[i]];
            tag[i]=0;
        }
        sort(pa+1,pa+m+1);
        int fa=b[1];
        for(int i=2;i<=m;i++)
        {
            fa=lca(fa,b[i]);
        }
        //cout<<fa<<endl;

        int c=0;
        int u=pa[1].second;
        tag[1]=1;
        int st=0;
        for(int i=2;i<=m;i++)
        {
            int v=pa[i].second;
            int now=lca(u,v);
            if(now==v)
            {
                tag[i]=1;
            }
            else 
            {
                if(now!=fa)c=1;
                if(st==0)st=v;
            }
        }
        for(int i=2;i<=m;i++)
        {
            int v=pa[i].second;
            int now=lca(u,v);
            if(now!=fa && now!=v)c=1;
            if(tag[i]==1 && now!=v)c=1;
            if(tag[i]==0 && now!=fa)c=1;
        }
        if(st!=0)
        {
            for(int i=1;i<=m;i++)
            {
                int v=pa[i].second;
                int now=lca(st,v);
                if(now!=fa && now!=v)c=1;
                //cout<<c<<" "<<fa<<" "<<st<<" "<<v<<" "<<now<<" "<<tag[i]<<endl;
                if(now!=v && tag[i]==0)
                {
                    c=1;
                }
                if(now!=fa && tag[i]==1)
                {
                    c=1;
                }
            }
        }
        if(c==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
