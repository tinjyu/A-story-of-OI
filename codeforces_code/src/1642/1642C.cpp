#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long int t,x,n,num[1000005],a[1000005],tag[1000005]
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			tag[i]=0;
		}
		sort(a+1,a+n+1);
		long long int p=1;
		int ans=n/2;
		for(int i=1;i<=n;i++)
		{
			if(tag[i]==1)continue;
			while(a[p]<a[i]*x)p++;
			if(a[p]==a[i]*x)
			{
				cout<<a[i]<<" "<<a[p]<<endl;
				tag[p]=1;
				tag[i]=1;
				ans--;
			}
		}
		cout<<ans<<endl;
	}
}
