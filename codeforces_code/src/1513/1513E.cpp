#include <iostream>
#include <algorithm>
using namespace std;
long long int n,p[100005],sum,ans=1,b=1,m[1000005];
int main(){
	cin>>n;
	m[0]=1;
	for(long long int i=1;i<=n;i++)
	{
		m[i]=m[i-1]*i;
		m[i]%=1000000007;
		cin>>p[i];
		//p[i]=i*100000;
		sum+=p[i];
	}
	if(sum%n!=0)
	{
		cout<<"0";
		return 0;
	}
	sum/=n;
	long long int mi=0,ma=0,eq=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]>sum)ma++;
		else if(p[i]<sum)mi++;
		else eq++;
	}
	if(ma<=1 || mi<=1)
	{
		for(long long int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=1000000007;
		}
	}
	else
	{
		for(long long int i=1;i<=ma;i++)
		{
			ans*=i;
			ans%=1000000007;
		}
		for(long long int i=1;i<=mi;i++)
		{
			ans*=i;
			ans%=1000000007;
		}
		ans*=2;
		ans%=1000000007;
		for(long long int i=n;i>=ma+mi+1;i--)
		{
			ans*=i;
			ans%=1000000007;
		}
	}
	sort(p+1,p+n+1);
	p[n+1]=-1;
	long long int now=0;
	for(int i=1;i<=n;i++)
	{
		now++;
		if(p[i]!=p[i+1])
		{
			b*=m[now];
			b%=1000000007;
			now=0;
		}
	}
	long long int tmp=1000000005,x=b;
	while(tmp>0)
	{
		if(tmp%2==1)ans*=x;
		x*=x;
		x%=1000000007;
		ans%=1000000007;
		tmp/=2;
	}
	cout<<ans<<endl;
}
