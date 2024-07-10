#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
long long int n,m,k,dp[505][505],tmp[505][505];
long long int map[505][505][4];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		long long int tmp;
		for(int j=1;j<m;j++)
		{
			cin>>tmp;
			map[i][j][0]=tmp;
			map[i][j+1][1]=tmp;
		}
	}
	for(int i=1;i<n;i++)
	{
		long long int tmp;
		for(int j=1;j<=m;j++)
		{
			cin>>tmp;
			map[i][j][2]=tmp;
			map[i+1][j][3]=tmp;
		}
	}
	if(k%2==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<"-1 ";
			}
			cout<<endl;
		}
		return 0;
	}
	k/=2;
	while(k--)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				tmp[i][j]=(1<<30);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int l=0;l<4;l++)
				{
					long long int tmpx=i,tmpy=j; 
					if(l==0)tmpy++;
					if(l==1)tmpy--;
					if(l==2)tmpx++;
					if(l==3)tmpx--;
					if(tmpx>=1 && tmpx<=n && tmpy<=m && tmpy>=1)
					{
						tmp[tmpx][tmpy]=min(tmp[tmpx][tmpy],dp[i][j]+map[i][j][l]);
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=tmp[i][j];
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)cout<<dp[i][j]*2<<" ";
		cout<<endl;
	}
	
} 
