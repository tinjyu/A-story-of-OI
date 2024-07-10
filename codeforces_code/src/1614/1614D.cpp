#include <iostream>
using namespace std;
long long int p=0;
long long int ge[1000005],n,a[1000005],dp[20000005],count[20000005],cnt[20000005],st[20000005],map[20000005][2];
int main(){
	int pp=0;
	for(int i=2;i<=20000005;i++)
	{
		if(dp[i]==0)
		{
			pp++;
			ge[pp]=i;
			for(int j=2;j*i<=20000005;j++)
			{
				dp[i*j]=1;
			}
		}
	}
	cin>>n;
	for(register int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<200;j++)
		{
			if(a[i]%j==0)cnt[j]++;
		}
		count[a[i]]++;
	}
	for(register int i=20000000;i>=200;i--)
	{
		st[i]=-1;
		for(register int j=1;j*i<=20000000;j++)
		{
			cnt[i]+=count[i*j];
		}
	}
	long long int ans=0;
	for(int i=20000000;i>=1;i--)
	{
		dp[i]=cnt[i]*i;
		if(cnt[i]==0)continue;
		
		for(int j=1;ge[j]*i<=20000000;j++)
		{
			dp[i]=max(dp[i],(cnt[i]-cnt[j*i])*i+dp[j*i]);
		}
		ans=max(dp[i],ans);
		//if(i<=6)cout<<dp[i]<<" ";
	}

	cout<<ans<<endl;
	return 0;
}
