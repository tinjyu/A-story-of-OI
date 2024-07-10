#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long int t,n,num[1000005],a[1000005];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		long long int cnt=0,p=0;
		a[n+1]=0;
		for(int i=1;i<=n;i++)
		{
			cnt++;
			if(a[i]!=a[i+1])
			{
				p++;
				num[p]=cnt;
				cnt=0;
			}
		}
		sort(num+1,num+p+1);
		long long int ans=p;
		long long int pp=1;
		for(int i=1;i<=n;i++)
		{
			cout<<ans<<" ";
			num[pp]--;
			if(num[pp]==0)
			{
				ans--;
				pp++;
			}
			
			ans++;
		}
		cout<<endl;
	}
}
