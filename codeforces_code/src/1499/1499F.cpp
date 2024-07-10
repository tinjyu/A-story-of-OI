#include <iostream>
using namespace std;
long long int n,m,k,u[100005],v[100005],map[100005][2],road[10005],dp[5005][5005],sum[5005];
int solve(int x,int fa)
{
	long long int g=road[x];
	for(int i=0;i<=n;i++)
	{
		sum[i]=1;
	}
	while(g!=-1)
	{
		long long int now=map[g][0];
		if(now!=fa)
		{
			find(now,fa);
			long long int sum1=0;
			for(int i=0;i<=k;i++)
			{
				sum1+=dp[now][i];
				sum[i]*=sum1;
			}
		}
		g=map[g][1];
	}
	g=road[x];
	while(g!=-1)
	{
		
	}

}
int main(){
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		cin>>u[i]>>v[i];
		map[i*2][0]=v[i];
		map[i*2][1]=road[u[i]];
		road[u[i]]=0;
		map[i*2+1][0]=u[i];
		map[i*2+1][1]=road[v[i]];
		road[v[i]]=0;
	}
	solve(1,-1);
}
