#include <iostream>
using namespace std;
long long int n,m,t,dp[805][805],c[805][805],bits[100005];
int main(){
	cin>>n>>m;
	bits[1]=1;
	for(int i=2;i<=400;i++)
	{
		bits[i]=bits[i-1]*2;
		bits[i]%=m;
	}
	c[1][1]=1;
	c[1][0]=1;
	for(int i=2;i<=400;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0)c[i][j]=0;
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=m;
		}
	}
	dp[1][1]=1;
	
	for(int i=2;i<=n;i++)
	{
		dp[i][i]=bits[i];
		for(int j=1;j<=i;j++)
		{
			if(i-j-1<=0)continue;
			for(int k=1;k<=i-j-1;k++)
			{
				//cout<<i<<" "<<j<<" "<<k<<endl;
				dp[i][j+k]+=dp[i-j-1][k]*c[k+j][j]%m*bits[j]%m;
				dp[i][j+k]%=m;
			//	cout<<dp[i-j-1][k]<<" "<<c[k+j][j]<<" "<<bits[j]<<endl;
			}
		}
	}
	long long int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=dp[n][i];
		ans%=m;
	}
	cout<<ans<<endl;
}
