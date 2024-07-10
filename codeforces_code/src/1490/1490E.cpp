#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct node{
	long long int id,val;
}tmp[1000005];
bool cmp(node a,node b)
{
	return a.val<b.val;
}
long long int t,n,tag[1000005],cnt,temp,d[1000005],sum[1000005];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>tmp[i].val;
		for(int i=1;i<=n;i++)
		{
			tag[i]=0;
			tmp[i].id=i;
		}
		sort(tmp+1,tmp+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			sum[i]=tmp[i].val+sum[i-1];
		}
		tag[tmp[n].id]=1;
		for(int i=n-1;i>=1;i--)
		{
			if(sum[i]<tmp[i+1].val)
			{
				break;
			}
			tag[tmp[i].id]=1;
		}
		long long int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(tag[i]==1)cnt++;
		}
		cout<<cnt<<endl;
		for(int i=1;i<=n;i++)
		{
			if(tag[i]==1)cout<<i<<" ";
		}
		cout<<endl;
	}
}
