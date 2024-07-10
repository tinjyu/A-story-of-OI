#include <iostream>
using namespace std;
long long int t,A[10000005],n,m,k;
long long int c(long long int a,long long int b)
{
	//cout<<a<<" "<<b<<endl;
	long long int p=A[a],q=A[a-b]*A[b];
	q%=1000000007;
	long long int tmp=1000000004,x=q;
	while(tmp>0)
	{
		if(tmp%2==1)q*=x;
		x*=x;
		x%=1000000007;
		q%=1000000007;
		tmp/=2;
	}
	return p*q%1000000007;
}
int main(){
	cin>>t;
	A[1]=1;
	A[0]=1;
	for(int i=2;i<=1000000;i++)
	{
		A[i]=A[i-1]*i;
		A[i]%=1000000007;
	}
	while(t--)
	{
		cin>>n>>m>>k;
		if(n==m)
		{
			cout<<n*k%1000000007<<endl;
			continue;
		}
		n=n-m;
		long long int p=0,q=1;
		long long int x=2,tmp=n+m-1;
		while(tmp>=1)
		{
			if(tmp%2==1)q*=x;
			x*=x;
			x%=1000000007;
			q%=1000000007;
			tmp/=2;
		}
		x=1;
		for(int i=1;i<=m;i++)
		{
			tmp=i*c(n+m-i-1,m-i);
			//cout<<tmp<<endl;
			tmp%=1000000007;
			p+=tmp*x;
			//cout<<p<<endl;
			x*=2;
			x%=1000000007;
			p%=1000000007;
		}
		//cout<<p<<" "<<q<<endl;
		tmp=1000000004,x=q;
		while(tmp>0)
		{
			if(tmp%2==1)q*=x;
			x*=x;
			x%=1000000007;
			q%=1000000007;
			tmp/=2;
		}
		p*=q;
		cout<<p*k%1000000007<<endl;
	}
}
