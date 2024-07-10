#include <iostream>
using namespace std;
long long int n,c[10000005],m,road[1000005],map[1000005][2];
long long int road2[1000005],map2[1000005][2],cnt[1000005],count,ans[1000005];
int find(int x,int fa)
{
	if(c[x]==1)cnt[x]=1;
	long long int g=road[x];
	while(g!=-1)
	{
		long long int now=map[g][0];
		if(now!=fa)
		{
			find(now,x);
			cnt[x]+=cnt[now];
		}
		g=map[g][1];
	}
	g=road[x];
	while(g!=-1)
	{
		long long int now=map[g][0];
		if(now!=fa)
		{
			if(cnt[now]>=2 || c[now]==1)
			{
				count++;
				map2[count][0]=x;
				map2[count][1]=road2[now];
				road2[now]=count;
			}
			if(m-cnt[now]>=2 || c[x]==1)
			{
				count++;
				map2[count][0]=now;
				map2[count][1]=road2[x];
				road2[x]=count;
			}
		}
		g=map[g][1];
	}
}
int dfs(int x)
{
	if(ans[x]!=-1)return 0;
	ans[x]=1;
	long long int g=road2[x];
	while(g!=-1)
	{
		long long int now=map2[g][0];
		dfs(now);
		g=map2[g][1];
	}
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		m+=c[i];
	}
	for(int i=1;i<=n;i++)
	{
		road[i]=-1;
		road2[i]=-1;
		ans[i]=-1;
	}
	for(int i=1;i<n;i++)
	{
		long long int a,b;
		cin>>a>>b;
		map[i*2][0]=b;
		map[i*2][1]=road[a];
		road[a]=i*2;
		map[i*2+1][0]=a;
		map[i*2+1][1]=road[b];
		road[b]=i*2+1;
	}
	find(1,0);
	for(int i=1;i<=n;i++)
	{
		if(c[i]==1)
		{
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==1)cout<<"1 ";
		else cout<<"0 ";
	}
}
