#include <iostream>
using namespace std;
long long int n,m,t;
char map[2005][2005];
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		long long int cnt=0,ans=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='#')
				{
					cnt++;
					ans*=2;
					ans%=1000000007;
				}
			}
		}
		if(cnt==n*m)
		{
			ans--;
			if(ans<0)ans+=1000000007;
		}
		cout<<ans<<endl;
	}
}
