#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
long long int n,m,k,dp[105][20005],t,a[100005],b[100005],sum[100005];
long long int tmp[1000005],map[505][505][4];
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+a[i]+b[i];
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=20000;j++)
			{
				dp[i][j]=(1<<30);
			}
		}
		dp[0][0]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=20000;j++)
			{
				if(dp[i][j]==(1<<30))continue;
				//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
				long long int anum=0,bnum=0;
				anum=a[i+1]*j+b[i+1]*(sum[i]-j);
				bnum=b[i+1]*j+a[i+1]*(sum[i]-j);
				
				dp[i+1][j+a[i+1]]=(dp[i+1][j+a[i+1]],dp[i][j]+anum*2);
				dp[i+1][j+b[i+1]]=(dp[i+1][j+b[i+1]],dp[i][j]+bnum*2);
				//cout<<" "<<i+1<<" "<<j+a[i+1]<<" "<<dp[i+1][j+a[i+1]]<<endl;
				//cout<<" "<<i+1<<" "<<j+b[i+1]<<" "<<dp[i+1][j+b[i+1]]<<endl;

			}
		}
		long long int ans=(1<<30);
		for(int i=0;i<=20000;i++)
		{
			ans=min(ans,dp[n][i]);
		}
		for(int i=1;i<=n;i++)
		{
			ans+=a[i]*a[i]*(n-1);
			ans+=b[i]*b[i]*(n-1);
		}
		cout<<ans<<endl;
	}
	
} 
