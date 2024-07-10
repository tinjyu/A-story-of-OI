#include <iostream>
#include <algorithm>
using namespace std;
long long int t,n,bits[10000005],a[1000005],pre[10000005];
int lg(int x)
{
	for(int i=1;i<=30;i++)
	{
		if(x<=bits[i])return bits[i]-x;
	}
}
int main(){
	bits[1]=1;
	for(int i=2;i<=30;i++)
	{
		bits[i]=bits[i-1]*2;
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int ans=10000000000;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		pre[n+1]=n;
		a[0]=-1;
		sort(a,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])pre[i]=pre[i-1];
			else pre[i]=i-1;
		}
		for(int i=0;i<=n;i++)
		{
			if(a[i]==a[i+1])continue;
			long long int nowans;
			for(int j=0;j<=30;j++)
			{
				if(i+bits[j]>n)break;
				long long int p=pre[i+bits[j]+1];
				nowans=lg(i)+lg(p-i)+lg(n-p);
				ans=min(ans,nowans);
			}
		}
		cout<<ans<<endl;
	}
}
