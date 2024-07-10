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
long long int n,m,q,k,d;
long long int p[1000005],a[1000005],b[1000005];
long long int x[1000005],y[1000005];
long long int tag[1000005];
long long int now[1000005];
long long int step[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
long long int t[1000005],pp;

long long int cyc[1000005],cnt;
long long int ans=0;


vector<int> nxt[1000006];
void dfs(int x)
{  
    if(tag[x]==1)return ;
    cnt++;
    tag[x]=1;
    cyc[cnt]=x;
    for(int i=0;i<=1;i++)
    {
        dfs(nxt[x][i]);
    }
    return ;
}
void check(int l,int r,int L,int R,int pre,int nxt,long long int tmp)
{
    int l1=0,r1=n+1,L1=0,R1=n+1;
    if(pre<=n)
    {
        if((pre<=r && pre>=l))return ;
        if(pre<l)l1=max(l1,pre);
        else r1=min(r1,pre);
    }
    else
    {
        pre-=n;
        if((pre<=R && pre>=L))return ;
        if(pre<L)L1=max(L1,pre);
        else R1=min(R1,pre);
    }
    if(nxt<=n)
    {
        if((nxt<=r && nxt>=l))return ;
        if(nxt<l)l1=max(l1,nxt);
        else r1=min(r1,nxt);
    }
    else
    {
        nxt-=n;
        if((nxt<=R && nxt>=L))return ;
        if(nxt<L)L1=max(L1,nxt);
        else R1=min(R1,nxt);
    }

    //cout<<l<<" "<<r<<" "<<l1<<" "<<r1<<" "<<L<<" "<<R<<" "<<L1<<" "<<R1<<endl;
    long long int count=1;
    if(l>r)
    {
        count*=(r1-l1-1)*(r1-l1)/2;
    }
    else 
    {
        count*=(r1-r)*(l-l1);
    }
    //cout<<count<<endl;
    if(L>R)
    {
        count*=(R1-L1-1)*(R1-L1)/2;
    }
    else 
    {
        count*=(R1-R)*(L-L1);
    }
    
    ans+=count*tmp;
    //cout<<count<<" "<<ans<<endl;
}
void solve()
{
    for(int i=cnt+1;i<=cnt*2;i++)
    {
        cyc[i]=cyc[i-cnt];
    }
    cyc[0]=cyc[cnt];
    for(int i=1;i<=cnt;i++)
    {
        long long int l=n,r=1,L=n,R=1;
        if(cyc[i]<=n)
        {
            l=cyc[i];
            r=cyc[i];
        }
        else 
        {
            R=cyc[i]-n;
            L=cyc[i]-n;
        }
        //cout<<i<<" "<<i<<endl;
        //check(l,r,L,R,cyc[i-1],cyc[i+1]);
        long long int now=i;
        for(int j=1;j<cnt-1;j++)
        {
            now++;
            if(cyc[now]<=n)
            {
                l=min(l,cyc[now]);
                r=max(cyc[now],r);
            }
            else 
            {
                L=min(L,cyc[now]-n);
                R=max(cyc[now]-n,R);
            }
            //cout<<i<<" "<<now<<endl;
            check(l,r,L,R,cyc[i-1],cyc[now+1],(now-i+1)/2);
        }
        if(i==1)
        {
            now++;
            if(cyc[now]<=n)
            {
                l=min(l,cyc[now]);
                r=max(cyc[now],r);
            }
            else 
            {
                L=min(L,cyc[now]-n);
                R=max(cyc[now]-n,R);
            }
            //cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
            ans+=(n-R+1)*L*(n-r+1)*l*cnt/2;
        }
        
    }
    return ;
}
int main(){
    cin>>n;
    ans=0;
    for(int i=1;i<=2*n;i++)
    {
        long long int a,b;
        cin>>a>>b;
        nxt[b].push_back(a);
        nxt[a].push_back(b);
    }
    for(int i=1;i<=2*n;i++)
    {
        if(tag[i]==0)
        {
            cnt=0;
            dfs(i);
        }
        else continue;
        //cout<<cnt<<endl;
        solve();
    }
    cout<<ans<<endl;
    return 0;
}