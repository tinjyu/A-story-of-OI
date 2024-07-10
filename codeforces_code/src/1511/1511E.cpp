#include <iostream>
using namespace std;
long long int n,m,cell[10000005],bits[10000005];
int main()
{
	cin>>n>>m;
	long long int ans=0,count=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char tmp;
			cin>>tmp;
			if(tmp=='o')
			{
				cell[i*m+j]=0;
				count++;
			}
			else cell[i*m+j]=1;
		}
	}
	bits[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		bits[i]=bits[i-1]*2;
		bits[i]%=998244353;
	}
	for(int i=1;i<=n;i++)
	{
		long long int cnt=0;
		for(int j=1;j<=m;j++)
		{
			if(cell[i*m+j]==1)
			{
				if(cnt>=2)
				{
					ans+=bits[count-2];
					long long int now=cnt-2;
					for(int k=3;k<=cnt;k++)
					{
						if(k%2==0)
						{
							now--;
							ans+=bits[count-k];
							continue;
						}
						ans+=now*bits[count-k];
						ans%=998244353;
						now--;
					}
				}
				
				cnt=0;
				continue;
			}
			cnt++;
			ans%=998244353;
		}
		if(cnt>=2)
		{
			ans+=bits[count-2];
			long long int now=cnt-2;
			for(int k=3;k<=cnt;k++)
			{
				if(k%2==0)
				{
					now--;
					ans+=bits[count-k];
					continue;
				}
				ans+=now*bits[count-k];
				ans%=998244353;
				now--;
			}
		}
		
	}
	for(int j=1;j<=m;j++)
	{
		long long int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cell[i*m+j]==1)
			{
				if(cnt>=2)
				{
					ans+=bits[count-2];
					long long int now=cnt-2;
					for(int k=3;k<=cnt;k++)
					{
						if(k%2==0)
						{
							now--;
							ans+=bits[count-k];
							continue;
						}
						ans+=now*bits[count-k];
						ans%=998244353;
						now--;
					}
				}
				ans%=998244353;
				cnt=0;
				continue;
			}
			cnt++;
			ans%=998244353;
		}
		if(cnt>=2)
		{
			ans+=bits[count-2];
			long long int now=cnt-2;
			for(int k=3;k<=cnt;k++)
			{
				if(k%2==0)
				{
					now--;
					ans+=bits[count-k];
					continue;
				}
				ans+=now*bits[count-k];
				ans%=998244353;
				now--;
			}
		}
	}
	cout<<ans%998244353<<endl;
}
