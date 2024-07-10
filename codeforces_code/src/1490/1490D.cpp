#include <iostream>
#include <cmath>
using namespace std;
long long int t,n,a[10000005],cnt,temp,d[100005];
int find(int s,int e,int deep)
{
	if(s>e)return 0;
	int p=0,ma=0;
	for(int i=s;i<=e;i++)
	{
		if(a[i]>ma)
		{
			ma=a[i];
			p=i;
		}
	}
	d[p]=deep;
	find(s,p-1,deep+1);
	find(p+1,e,deep+1);
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		find(1,n,0);
		for(int i=1;i<=n;i++)cout<<d[i]<<" ";
		cout<<endl;
	}
}
