#include <iostream>
#include <map>
#include <vector>
using namespace std;
long long int n,m,a[1000005],b[1000005],x,d,dp[1000005],lpos,rpos,val;
long long int tree[1000005],cnt[1000005];
long long int p[1000005];
long long int div(long long int x)
{
	long long int tmp=998244351,val=1;
	while(tmp>0)
	{
		if(tmp%2==1)val*=x;
		tmp/=2;
		x*=x;
		val%=998244353;
		x%=998244353;
	}
	return val;
}
int build(int s,int e,int t)
{
	if(s==e)return tree[t]=cnt[s];
	return tree[t]=build(s,(s+e)/2,t*2)+build((s+e)/2+1,e,t*2+1);
}
int find(int s,int e,int t)
{
	if(e<lpos || s>rpos)return 0;
	if(lpos<=s && e<=rpos)
	{
		val+=tree[t];
		return 0;
	}
	find(s,(s+e)/2,t*2);
	find((s+e)/2+1,e,t*2+1);
	return 0;
}
int change(int s,int e,int t)
{
	if(lpos<s || e<lpos)return tree[t];
	if(s==e)
	{
		return tree[t]=cnt[s];
	}
	return tree[t]=change(s,(s+e)/2,t*2)+change((s+e)/2+1,e,t*2+1);
}
int main(){
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=200000;i++)
	{
		p[i]=p[i-1]*i;
		p[i]%=998244353;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	build(1,200000,1);
	
	long long int ans=1;
	for(int i=1;i<=200000;i++)
	{
		if(cnt[i]!=0)ans=(ans*p[cnt[i]])%998244353;
	}
	ans=div(ans);
	long long int count=0,pre=1,ma=0;
	for(int i=1;i<=min(n-1,m);i++)
	{
		lpos=1,rpos=b[i]-1;
		val=0;
		find(1,200000,1);
		count+=(((pre*val)%998244353)*p[n-i])%998244353;
		count%=998244353;
		pre*=cnt[b[i]];
		pre%=998244353;
		if(cnt[b[i]]==0)break;
		ma++;
		cnt[b[i]]--;
		lpos=b[i];
		change(1,200000,1);
	}
	ans=(ans*count)%998244353;
	if(ma==n-1 && cnt[b[n]]==1)
	{
		ans++;
		ans%=998244353;
	}
	cout<<ans<<endl;
}
