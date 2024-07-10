#include <iostream>
using namespace std;
long long int t,n,cnt[1000005],road[1000005],map[1000005][2];
int find(int x,int fa,int p)
{
	long long int g=road[x];
	cnt[x]*=p;
	while(g!=-1)
	{
		long long int now=map[g][0];
		if(now!=fa)
		{
			find(now,x,p*-1);
		}
		g=map[g][1];
	}
	return 0;
}
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cnt[i]=0,road[i]=-1;
		
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
			cnt[a]++;
			cnt[b]++;
		}
		find(1,0,1);
		for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";
		cout<<endl;
	}
} 
