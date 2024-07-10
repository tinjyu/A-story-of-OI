#include <iostream>
#include <cmath>
#include <algorithm> 
#include <set>
using namespace std;
long long int sum[1000005],n,m,k,t,a[1000005],b[100005],p;
long long int tmp[1000005],map[505][505][4];
long long int g[1000005];
long long int dp[1000005];
inline int read(){
    register int x = 0, t = 1;
    register char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            t=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*t;
}
int main(){
	n=read();
	p=read();
	for(int i=1;i<=n;i++)
	{
		//cin>>a[i];
		a[i]=read();
	}
	sort(a+1,a+n+1);
	long long int cnt=0;
	set<long long int> use;
	for(int i=1;i<=n;i++)
	{
		long long int tmp=a[i];
		int change=0;
		while(true)
		{
			if(tmp==0)break;
			if(tmp & 1) tmp >>=1;
			else if (tmp & 3)break;
			else tmp >>=2;
			if(use.count(tmp)==1)
			{
				change=1;
				break;
			}
		}
		if(change==0)
		{
			cnt++;
			g[cnt]=a[i];
			use.insert(a[i]);
		}
	}
	n=cnt;
	for(int i=1;i<=n;i++)a[i]=g[i];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=200000;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
		if(dp[i]>=1000000007)dp[i]-=1000000007;
		//cout<<dp[i]<<" ";
	}
	//cout<<endl;
	sum[0]=1;
	for(int i=1;i<=200000;i++)
	{
		sum[i]=sum[i-1]+dp[i];
		if(sum[i]>=1000000007)sum[i]-=1000000007;
	}
	long long int ans=0;
	for(int i=1;i<=n;i++)
	{
		long long int tmp=0;
		while(a[i]>0)
		{
			a[i]/=2;
			tmp++;
		}
		cout<<tmp<<" "<<p<<endl;
		if(tmp<p)ans+=sum[p-tmp-1];
		if(ans>=1000000007)ans-=1000000007;
	}
	cout<<ans<<endl;
}
