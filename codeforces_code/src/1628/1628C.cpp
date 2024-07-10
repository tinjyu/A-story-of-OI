#include <iostream>
using namespace std;
long long int t,a[1005][1005],n,m,k,cnt[1005][1005];
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				cnt[i][j]=0;
			}
		}
		long long int ans=0;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(cnt[i-1][j]%2==0)
				{
					ans=(ans xor a[i][j]);
					cnt[i][j-1]++;
					cnt[i][j+1]++;
					cnt[i+1][j]++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
