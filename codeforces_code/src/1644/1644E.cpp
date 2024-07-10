#include <iostream>
using namespace std;
long long int n,t,p[1000005];
long long int ma[1000005],road[1000005],map[1000005][4],f[1000005],p1,q1,ans;
long long int div(long long int x)
{
	long long int val=1;
	long long int tmp=998244351;
	while(tmp>=1)
	{
		if(tmp%2==1)val*=x;
		tmp/=2;
		x=x*x;
		x%=998244353;
		val%=998244353;
	}
	return val;
}
int find(int x,int fa)
{
	ans+=p1*div(q1);
	ans%=998244353;
	//cout<<p1<<" "<<q1<<" "<<x<<" "<<ans<<endl;
	long long int g=road[x];
	while(g!=-1)
	{
		long long int now=map[g][0];
		if(now!=fa)
		{
			long long int p2=map[g][3],q2=map[g][2];
			while(p2!=1)
			{
				f[p[p2]]--;
				p2=p2/p[p2];
			}
			while(q2!=1)
			{
				f[p[q2]]++;
				ma[p[q2]]=max(ma[p[q2]],f[p[q2]]);
				q2=q2/p[q2];
			}
			p1=(p1*map[g][3])%998244353;
			q1=(q1*map[g][2])%998244353;
			find(now,x);
			p2=map[g][3],q2=map[g][2];
			while(p2!=1)
			{
				f[p[p2]]++;
				p2=p2/p[p2];
			}
			while(q2!=1)
			{
				f[p[q2]]--;
				q2=q2/p[q2];
			}
			p1=(p1*map[g][2])%998244353;
			q1=(q1*map[g][3])%998244353;
		}
		g=map[g][1];
	}
}
int main(){
	p1=1;
	q1=1;
	for(int i=2;i<=200000;i++)
	{
		if(p[i]==0)
		{
			for(int j=i;j<=200000;j+=i)
			{
				p[j]=i;
			}
		}
	}
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			road[i]=-1;
			ma[i]=0;
			f[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			long long int a,b,x,y;
			cin>>a>>b>>x>>y;
			map[i*2][0]=b;
			map[i*2][1]=road[a];
			map[i*2][2]=x;
			map[i*2][3]=y;
			road[a]=i*2;
			map[i*2+1][0]=a;
			map[i*2+1][1]=road[b];
			map[i*2+1][2]=y;
			map[i*2+1][3]=x;
			road[b]=i*2+1;
		}
		find(1,-1);
		for(int i=1;i<=n;i++)
		{
			if(ma[i]!=0)
			{
				for(int j=1;j<=ma[i];j++)ans=(ans*i)%998244353;
			}
		}
		cout<<ans<<endl;
	}
}
