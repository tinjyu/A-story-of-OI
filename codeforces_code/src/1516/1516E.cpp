#include <iostream>
using namespace std;
long long int n,k,dp[405][405],p=0,g[405][405],ans[10005],c[1005][1005],pl[100005][2];

long long int C(long long int a,long long int b)
{
	long long int x=pl[b][0];
	long long int y=pl[b][1];
	long long int tmp=1000000005,temp=y;
	while(tmp>0)
	{
		if(tmp%2==1)x*=temp;
		temp*=temp;
		tmp/=2;
		temp%=1000000007;
		x%=1000000007;
	}
	//cout<<" "<<a<<" "<<b<<" "<<x<<endl;
	return x;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<=2*k;i++)
	{
		dp[i][0]=1;
	}
	c[0][0]=1;
	pl[1][0]=n;
	pl[1][1]=1;
	for(int i=2;i<=2*k;i++)
	{
		pl[i][0]=pl[i-1][0]*(n-i+1);
		pl[i][1]=pl[i-1][1]*i;
		pl[i][0]%=1000000007;
		pl[i][1]%=1000000007;
	}
	for(int i=1;i<=400;i++)
	{
		for(int j=0;j<=i;j++)
		{
			c[i][j]=c[i-1][j];
			if(j!=0)c[i][j]+=c[i-1][j-1];
			if(c[i][j]>=1000000007)c[i][j]-=1000000007;
		}
	}
	for(int i=1;i<=2*k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			dp[i][j]=dp[i-1][j]+(i-1)*dp[i-1][j-1];
			dp[i][j]%=1000000007;
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=1;i<=2*k;i++)
	{
		for(int j=(i+1)/2;j<=k;j++)
		{
			for(int l=0;i-l>=j;l++)
			{
				if(l%2==0)g[i][j]+=dp[i-l][j]*c[i][i-l];
				else g[i][j]-=dp[i-l][j]*c[i][i-l];
				if(g[i][j]<0)g[i][j]+=1000000007;
				
				g[i][j]%=1000000007;
				//cout<<i<<" "<<j<<" "<<l<<" "<<g[i][j]<<" "<<dp[i-l][j]<<endl;
			}
			//cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
			if(n>=i)ans[j]+=g[i][j]*C(n,i);
			ans[j]%=1000000007;
		}
	}
	ans[0]=1;
	for(int j=2;j<=k;j++)
	{
		ans[j]+=ans[j-2];
	}
	
	for(int i=1;i<=k;i++)
	{
		cout<<ans[i]%1000000007<<" ";
	}
}
