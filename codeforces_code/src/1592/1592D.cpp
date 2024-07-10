#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
long long int tag[100005],n,road[1000005],map[10000005][2],euler[1000005],p=0,ma;
int dfs(int x,int fa)
{
	p++;
	euler[p]=x;
	long long int g=road[x];
	while(g!=-1)
	{
		long long int now=map[g][0];
		if(now!=fa)
		{
			
			dfs(now,x);
			p++;
			euler[p]=x;
		}
		g=map[g][1];
	}
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)road[i]=-1;
	for(int i=1;i<n;i++)
	{
		long long int u,v;
		cin>>u>>v;
		map[i*2][0]=v;
		map[i*2][1]=road[u];
		road[u]=i*2;
		map[i*2+1][0]=u;
		map[i*2+1][1]=road[v];
		road[v]=i*2+1;
	}
	cout<<"? ";
	cout<<n<<" ";
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	cin>>ma;
	dfs(1,-1);
	long long int l=1,r=p;
	while(l<r-1)
	{
		long long int mid=(l+r)/2;
		for(int i=1;i<=n;i++)tag[i]=0;
		cout<<"? ";
		long long int cnt=0;
		for(int i=l;i<=mid;i++)
		{
			if(tag[euler[i]]==0)
			{
				//cout<<euler[i]<<" ";
				cnt++;
				tag[euler[i]]=1;
			}
		}
		cout<<cnt<<" ";
		for(int i=1;i<=n;i++)
		{
			if(tag[i]==1)cout<<i<<" ";
		}
		cout<<endl;
		long long int tmp;
		cin>>tmp;
		if(tmp<ma)
		{
			l=mid;
		}
		else 
		{
			r=mid;
		}
	}
	cout<<"! "<<euler[l]<<" "<<euler[r]<<endl;
} 
