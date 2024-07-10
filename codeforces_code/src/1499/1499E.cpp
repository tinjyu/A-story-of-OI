#include <iostream>
using namespace std;
long long int dp[1005][1005][2],sum[1005][1005];
string x,y;
int main(){
	cin>>x>>y;
	x=" "+x;
	y=" "+y;
	int n=x.size();
	int m=y.size();
	sum[0][0]=1;
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i>0)dp[i][j][0]++;
			if(j>0)dp[i][j][1]++;
			if(i>0 && x[i]!=x[i-1])dp[i][j][0]+=dp[i-1][j][0];
			if(i>0 && x[i]!=y[j])dp[i][j][0]+=dp[i-1][j][1];
			if(j>0 && y[j]!=y[j-1])dp[i][j][1]+=dp[i][j-1][1];
			if(j>0 && y[j]!=x[i])dp[i][j][1]+=dp[i][j-1][0];
			ans+=dp[i][j][0];
			ans+=dp[i][j][1];
			//cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
			dp[i][j][0]%=998244353;
			dp[i][j][1]%=998244353;
			ans%=998244353;
		}
	}
	//cout<<ans<<endl;
	for(int i=1;i<n;i++)
	{
		long long int p=i,cnt=1;
		while(x[p]!=x[p+1] && p+1<n)
		{
			p++;
			cnt++;
		}
		cnt=cnt*(cnt+1)/2*m;
		
		cnt%=998244353;
		ans-=cnt;
		if(ans<0)ans+=998244353;
		i=p;
	}
	for(int i=1;i<m;i++)
	{
		long long int p=i,cnt=1;
		while(y[p]!=y[p+1] && p+1<m)
		{
			p++;
			cnt++;
		}
		//cout<<cnt<<endl;
		cnt=cnt*(cnt+1)/2*n;
		cnt%=998244353;
		ans-=cnt;
		if(ans<0)ans+=998244353;
		i=p;
	}
	cout<<ans<<endl;
}
