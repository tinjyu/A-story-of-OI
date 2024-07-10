#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long int ans,pre,t,x,n,b[1000005],a[1000005],tend[10000005],q,tar[10005],oper[1000005][2];
int sw(int p)
{
	for(int i=1;i<=p;i++)
	{
		q++;
		oper[q][0]=pre+p+i-1;
		oper[q][1]=a[i];
	}
	pre+=2*p;
	ans++;
	tend[ans]=2*p;
	for(int i=1;i<=p/2;i++)
	{
		swap(a[i],a[p-i+1]);
	}
	return 0;
}
int main()
{
	cin>>t;
	q=0;
	ans=0;
	while(t--)
	{
		pre=0;
		ans=0;
		q=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		int cnt=0;
		b[n+1]=0;
		long long int check=0;
		long long int pp=1,qq=n/2+1;
		for(int i=1;i<=n;i++)
		{
			cnt++;
			if(b[i]!=b[i+1])
			{
				if(cnt%2==1)
				{
					check=1;
					break;
				}
				for(int j=1;j<=cnt/2;j++)
				{
					tar[pp]=b[i];
					tar[qq]=b[i];
					pp++;
					qq++;
				}
				cnt=0;
				
			}
		}
		if(check==1)
		{
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]==tar[i])
				{
					sw(j);
					sw(i);
					break;
				}
			}
		}
		ans++;
		tend[ans]=n;
		cout<<q<<endl;
		for(int i=1;i<=q;i++)
		{
			cout<<oper[i][0]<<" "<<oper[i][1]<<endl;
		}
		cout<<ans<<endl;
		for(int i=1;i<=ans;i++)
		{
			cout<<tend[i]<<" ";
		}
		cout<<endl;
	}
}
