#include <iostream>
using namespace std;
long long int n,d[100][50005],m,ans=1;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	ans*=m;
	ans%=998244353;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>d[i][j];
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int k=i;k>=2;k--)
			{
				if(d[k][j]<d[k-1][j])
				{
					swap(d[k][j],d[k-1][j]);
				}
			}
		}
		long long int now=1;
		for(int i=1;i<=n;i++)
		{
			if(d[i][j]<=i)
			{
				now=0;
				break;
			}
			now*=(d[i][j]-i);
		}
		ans-=now;
		if(ans<0)ans+=998244353;
	}
	long long int x=1;
	for(int i=1;i<=n;i++)
	{
		x*=i;
		x%=998244353;
	}
	long long int tmp=998244351;
	while(tmp>0)
	{
		if(tmp%2==1)ans*=x;
		x*=x;
		x%=998244353;
		ans%=998244353;
		tmp/=2;
	}
	cout<<ans<<endl;
}
