#include <iostream>
using namespace std;
long long int ans=0,n,num[1005],bin[25][400005][2],cnt[25][400005],ma[25],dp[1100000][2],tag[1005],bits[10005];
string s[1005];
int find(int p)
{
	if(dp[p][0]!=-1)return 0;
	dp[p][0]=0;
	for(int i=1;i<=n;i++)
	{
		if((p & bits[i])!=0)
		{
			long long int tmp=(p xor bits[i]);
			//cout<<p<<" "<<tmp<<endl;
			find(tmp);
			if(dp[tmp][1]<0)continue;
			if(dp[tmp][1]>=ma[i])
			{
				dp[p][0]=max(dp[tmp][0]+cnt[i][dp[tmp][1]],dp[p][0]);
				dp[p][1]=dp[tmp][1]-num[i];
				ans=max(dp[p][0],ans);
			}
			else
			{
				long long int l=0,r=s[i].length()-1;
				while(l<=r)
				{
					long long int mid=(l+r)/2;
					//cout<<" "<<mid<<" "<<bin[i][mid][0]<<" "<<bin[i][mid][1]<<endl; 
					if(bin[i][mid][0]<dp[tmp][1])l=mid+1;
					else if(bin[i][mid][0]>dp[tmp][1])r=mid-1;
					else
					{
						ans=max(ans,dp[tmp][0]+bin[i][mid][1]);
						l=mid+1; 
					}
				}
			}
		}
	}
	//cout<<p<<" "<<dp[p][0]<<" "<<dp[p][1]<<endl;
	return 0;
}
int main(){
	cin>>n;
	bits[1]=1;
	for(int i=2;i<=n+1;i++)bits[i]=bits[i-1]*2;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=bits[n+1]-1;i++)
	{
		dp[i][0]=-1;
		dp[i][1]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		long long int count=0;
		for(int j=0;j<s[i].length();j++)
		{
			if(s[i][j]=='(')count--;
			else count++;
			ma[i]=max(ma[i],count);
			if(count>=0)cnt[i][count]++;
			bin[i][j][0]=ma[i];
			bin[i][j][1]=cnt[i][ma[i]];
		}
		num[i]=count;
	}
	find(bits[n+1]-1);
	cout<<ans<<endl;
	return 0;
}
