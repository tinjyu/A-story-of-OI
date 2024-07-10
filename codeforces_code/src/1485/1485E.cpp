#include <iostream>
using namespace std;
long long int q[1000005],p[1000005],nxt[1000005],d[1000005],t,n,ad[1000005],sub[1000005],v[1000005],a[1000005],dp[1000005],ma[1000005],mi[1000005],road[1000005],map[1000005][2];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=2;i<=n;i++)cin>>v[i];
		for(int i=2;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)road[i]=-1;
		for(int i=2;i<=n;i++)
		{
			map[i][0]=i;
			map[i][1]=road[v[i]];
			road[v[i]]=i;
		}
		d[1]=1;
		q[1]=1;
		long long int pp=1;
		for(int i=1;i<=n;i++)
		{
			long long int g=road[q[i]];
			while(g!=-1)
			{
				long long int now=map[g][0];
				d[now]=d[q[i]]+1;
				pp++;
				q[pp]=now;
				g=map[g][1];
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<d[i]<<endl;
			p[i]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			nxt[i]=p[d[i]];
			p[d[i]]=i;
		}
		dp[1]=0;
		long long int ans=0;
		for(int i=2;i<=n;i++)
		{
			ma[i]=-99999999999999;
			mi[i]=99999999999999;
			ad[i]=-99999999999999;
			sub[i]=-99999999999999;
			long long int g=p[i];
			while(g!=-1)
			{
				long long int now=g;
				ma[i]=max(ma[i],a[now]);
				mi[i]=min(mi[i],a[now]);
				ad[i]=max(ad[i],dp[v[now]]+a[now]);
				sub[i]=max(sub[i],dp[v[now]]-a[now]);
				g=nxt[g];
			}
			g=p[i];
			while(g!=-1)
			{
				long long int now=g;
				dp[now]=max(dp[v[now]]+max(a[now]-mi[i],ma[i]-a[now]),max(ad[i]-a[now],sub[i]+a[now]));
				ans=max(ans,dp[now]);
				//cout<<now<<" "<<dp[now]<<endl;
				g=nxt[g];
			}
		}
		cout<<ans<<endl;
	}
}
