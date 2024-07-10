#include <iostream>
#include <cmath>
#include <algorithm> 
#include <set>
using namespace std;
long long int n,m,t,u[1000005],v[1000005],w[1000005],bits[1000005],f[1000005];
int qs(int s,int e)
{
	long long int l=s,r=e,mid=(w[l]+w[r])/2;
	while(l<=r)
	{
		while(w[l]<mid)l++;
		while(w[r]>mid)r--;
		if(l<=r)
		{
			swap(u[l],u[r]);
			swap(v[l],v[r]);
			swap(w[l],w[r]);
			l++;
			r--;
		}
	}
	if(r>s)qs(s,r);
	if(e>l)qs(l,e);
}
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	cin>>t;
	bits[1]=1;
	for(int i=2;i<=32;i++)bits[i]=bits[i-1]*2;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>u[i]>>v[i]>>w[i];
		}
		qs(1,m);
		long long int ans=0;
		while(true)
		{
			for(int i=1;i<=n;i++)f[i]=i;
			long long int cnt=0;
			long long int bitsmask=0;
			for(int i=1;i<=m;i++)
			{
				if(find(u[i])==find(v[i]))continue;
				cnt++;
				f[find(u[i])]=find(v[i]);
				if(cnt==n-1)
				{
					long long int tmp=w[i];
					while(tmp>0)
					{
						tmp/=2;
						bitsmask++;
					}
					break; 
				}
			}
			if(bitsmask==0)break;
			ans+=bits[bitsmask];
			for(int i=1;i<=m;i++)
			{
				if(w[i]>=bits[bitsmask+1])
				{
					m=i-1;
					break;
				}
			}
			for(int i=1;i<=m;i++)
			{
				if(w[i]>=bits[bitsmask])
				{
					w[i]-=bits[bitsmask];
				}
			}
			qs(1,m);
		}
		cout<<ans<<endl;
	}
}
