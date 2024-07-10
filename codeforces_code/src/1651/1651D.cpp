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
long long int nxt[100005][35];
long long int now[1000005];
long long int step[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
long long int ans[1000005][2];
long long int t[1000005],pp;
set<pair<int,int> > st;
map<pair<int,int>,int> mp;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)
    {
        st.insert(make_pair(x[i],y[i]));
        mp.insert(make_pair(make_pair(x[i],y[i]),i));
    }
    for(int i=1;i<=n;i++)
    {
        int c=0;
        for(int j=0;j<4;j++)
        {
            int tmpx=x[i]+step[j][0],tmpy=y[i]+step[j][1];
            if(st.count(make_pair(tmpx,tmpy))==0)
            {
                c=1;
                ans[i][0]=tmpx;
                ans[i][1]=tmpy;
                break;
            }
        }
        if(c==1)
        {
            pp++;
            t[pp]=i;
            tag[i]=1;
        }
    }
    
    int p=1;
    while(p<=pp)
    {
        int nowx=x[t[p]],nowy=y[t[p]];
        for(int i=0;i<4;i++)
        {
            int tmpx=nowx+step[i][0],tmpy=nowy+step[i][1];
            if(mp.count(make_pair(tmpx,tmpy))==1)
            {
                int id=mp[make_pair(tmpx,tmpy)];
                if(tag[id]==0)
                {
                    ans[id][0]=ans[t[p]][0];
                    ans[id][1]=ans[t[p]][1];
                    pp++;
                    t[pp]=id;
                    tag[id]=1;
                }
            }
        }
        p++;
    }
    for(int i=1;i<=n;i++)cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    return 0;
}