#include <iostream>
#include <cstdlib>
using namespace std;
long long int n,t,a[100005],sum[2005][2005];
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			sum[i][i]=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				sum[i][j]=(sum[i][j-1] xor a[j]);
			}
		}
		long long int c=0;
		if(sum[1][n]==0)c=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(sum[1][i]==sum[i+1][j] && sum[i+1][j]==sum[j+1][n])c=1;
			}
		}
		if(c==1)cout<<"YES"<<endl;
		else cout<<"no"<<endl;
	}
}
