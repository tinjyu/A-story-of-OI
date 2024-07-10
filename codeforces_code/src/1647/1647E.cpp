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
using namespace std;
long long int n,m,q,k;
long long int p[1000005],a[1000005];
long long int tag[1000005];
long long int nxt[100005][35];
long long int now[1000005];
long long int ans[1000005];

vector<int> node[1000005];

pair<int,int> pa[1000005];

int main(){
    cin>>n;
    long long int cnt=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        now[i]=i;
        nxt[i][0]=p[i];
        if(tag[p[i]]==1)cnt++;
        tag[p[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    long long int ti=(mx-n)/cnt;

    for(int j=1;j<=30;j++)
    {
        for(int i=1;i<=n;i++)
        {
            nxt[i][j]=nxt[nxt[i][j-1]][j-1];
        }
    }
    long long int pp=0;
    while(ti>0)
    {
        if(ti%2==1)
        {
            for(int i=1;i<=n;i++)
            {
                now[i]=nxt[now[i]][pp];
            }
        }
        pp++;
        ti/=2;
    }
    for(int i=1;i<=n;i++)
    {
        node[now[i]].push_back(i);
    }
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=n)
        {
            cnt++;
            pa[cnt].first=a[i];
            pa[cnt].second=i;
        }
    }
    sort(pa+1,pa+cnt+1);
    for(int i=1;i<=n;i++)tag[i]=0;
    pp=n;
    set <long long int> st;
    for(int i=1;i<=n;i++)
    {
        st.insert(i);
    }   
    for(int i=cnt;i>=1;i--)
    {
        ans[node[pa[i].second][0]]=a[pa[i].second];
        st.erase(a[pa[i].second]);
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]!=0)continue;
        //cout<<a[now[i]]<<" "<<now[i]<<" ";
        long long int tmp=*st.upper_bound(a[now[i]]);
        //cout<<tmp<<endl;
        ans[i]=tmp;
        st.erase(tmp);
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";

    return 0;
}