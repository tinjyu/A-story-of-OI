#include <iostream>
using namespace std;
long long int q[1000005],b[1000005],n,nxt[1000005],road[1000005],map[10000005][2],a[1000005];
string s;
int main(){
	cin>>n;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')a[i]=0;
		
		if(s[i]=='1')a[i]=1;
		if(s[i]=='?')a[i]=2;
	}
	long long int len=0,pre=2,quest=0;
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='?')
		{
			len++;
			quest++;
		}
		else
		{
			quest=0;
			if(pre==a[i])len++;
			else 
			{
				len=1;
				pre=a[i];
			}
		}
		nxt[i]=len+q[i+len];
		q[i]=quest;
	}
	for(int i=1;i<=n;i++)road[i]=-1;
	len=0;
	a[n+1]=1000;
	pre=n;
	long long int cnt=0;
	long long int now=2;
	a[0]=0;
	for(int i=n;i>=1;i--)
	{
		if(now==2)now=a[i];
		if(now!=2 && now!=a[i-1] && a[i-1]!=2)
		{
			cout<<i<<" ";
			for(int j=1;j<=nxt[i];j++)
			{
				cnt++;
				map[cnt][0]=i;
				map[cnt][1]=road[j];
				road[j]=cnt;
			}
			now=2;
		}
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		long long int now=1;
		long long int p=0;
		long long int ans=0;
		long long int g=road[i];
		while(g!=-1)
		{
			p++;
			b[p]=map[g][0];
			g=map[g][1];
		}
		long long int pp=1;
		while(now<=n)
		{
			if(nxt[now]>=i)
			{
				ans++;
				now+=i;
				continue;
			}
			while(pp<=p && b[pp]<now)pp++;
			if(p+1==pp)break;
			now=b[pp];
			
		}
		cout<<ans<<endl;
	}
}
