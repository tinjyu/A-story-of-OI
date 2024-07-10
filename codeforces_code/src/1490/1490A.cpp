#include <iostream>
#include <cmath>
using namespace std;
long long int t,n,a[10000005],cnt,temp;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		long long int ans=0;
		for(int i=1;i<n;i++)
		{
			long long int tmp1=min(a[i],a[i+1]),tmp2=max(a[i],a[i+1]);
			while(tmp1*2<tmp2)
			{
				tmp1*=2;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
