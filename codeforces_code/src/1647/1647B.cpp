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
#include <queue>
using namespace std;
long long int MOD=998244353;
long long int n,m,k,s;
long long int a[1000005],x[1000005],p[1000004],siz[1000004],dis[1000005],lmx[10000005],rmx[1000005];
long long int lp[1000005],rp[1000005];
long long int tree[1000005][2],lazy[1000005][2];
long long int mx1=0,mx2=0;
char mp[1005][1005];
long long int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
long long int tag[1005][1005];
int r,l,u,d,cnt;
int dfs(int x,int y)
{
    cnt++;
    tag[x][y]=1;
    r=max(y,r);
    l=min(y,l);
    u=min(x,u);
    d=max(x,d);
    for(int i=0;i<4;i++)
    {
        long long int tmpx=x+step[i][0],tmpy=y+step[i][1];
        if(tmpx>=1 && tmpx<=n && tmpy>=1 && tmpy<=m && tag[tmpx][tmpy]==0 && mp[tmpx][tmpy]=='1')
        {
            dfs(tmpx,tmpy);
        }
    }
    return 0;
}

int main(){
    long long int T;
    int tmp=0;
    cin>>T;
    tmp=T;
    int id=0;
    while(T--)
    {
        id++;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
                tag[i][j]=0;
            }
        }
        int c=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(tag[i][j]==0 && mp[i][j]=='1')
                {
                    cnt=0;
                    l=j;
                    r=j;
                    u=i;
                    d=i;
                    dfs(i,j);
                    if(cnt!=(r-l+1)*(d-u+1))
                    {
                        c=1;
                    }
                }
            }
        }
        if(c==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}