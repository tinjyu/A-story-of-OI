#include <iostream>
#include <cstdlib>
using namespace std;
long long int n,t,a[1000005],dp[10000005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long int c=1,sum=0;
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]%2==1)c=0;
		sum+=a[i];
	}
	if(sum%2==1)
	{
		cout<<"0"<<endl;
		return 0;
	}
	dp[0]=1;
	long long int ma=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=ma;j>=0;j--)
		{
			if(dp[j]==1)dp[j+a[i]]=1;
		}
		ma+=a[i];
	}
	if(dp[sum/2]==0)
	{
		cout<<"0";
		return 0;
	}
	if(c==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==1)
			{
				cout<<"1"<<endl;
				cout<<i<<endl;
				return 0;
			}
		}
	}
	while(c==1)
	{
		sum=0;
		for(int i=1;i<=n;i++)
		{
			a[i]/=2;
			if(a[i]%2==1)c=0;
			sum+=a[i];
		}
		if(sum%2==1)
		{
			cout<<"0"<<endl;
			return 0;
		}
		if(c==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]%2==1)
				{
					cout<<"1"<<endl;
					cout<<i<<endl;
					return 0;
				}
			}
		}
	}
}
