#include <iostream>
using namespace std;
long long int n,k,pos[1000005],a[1000005],s[1000005],sum[1000005],p[1000005];
long long int c(long long int n,long long int m)
{
	long long int ret=p[n];
	long long int tmp=p[m]*p[n-m];
	tmp%=998244353;
	long long int x=tmp,cnt=998244351;
	tmp=1;
	while(cnt>0)
	{
		if(cnt%2==1)ret*=x;
		cnt/=2;
		x*=x;
		x%=998244353;
		ret%=998244353;
	}
	return ret;
}
int main(){
	cin>>n>>k;
	p[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		p[i]=p[i-1]*i;
		p[i]%=998244353;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//a[i]=i;
		pos[a[i]]=i;
	}
	p[n+1]=0;
	long long int cnt=0;
	for(int i=1;i<n;i++)
	{
		if(pos[a[i]+1]<pos[a[i+1]+1])
		{
			cnt++;
		}
		//cout<<s[i]<<" ";
	}
	long long int ans=0;
	//cout<<cnt<<endl;
	for(long long int i=0;i<=cnt;i++)
	{
		if(n-i<=k)
		{
			long long int now=1,x=k-(n-i)+1,tmp=n;
			//cout<<k<<" "<<n-i<<" "<<cnt<<" "<<i<<" "<<c(k,n-i)<<endl;
			ans+=c(k,n-i)*c(cnt,i);
			ans%=998244353;
			//if(i>cnt-100)cout<<ans<<endl;
		}
		
	}
	cout<<ans<<endl;
}

