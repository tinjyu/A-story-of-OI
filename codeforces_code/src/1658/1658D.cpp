#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
long long int t,n,k,a[1000005],tag[1000005],check[1000005],l,r;
int ch(int x)
{
	for(int i=1;i<=n;i++)
	{
		if((a[i] xor x)<l || (a[i] xor x)>r)return 0;
	}
	return 1;
}
int main()
{
	cin>>t;
	while(t--)
	{	
		cin>>l>>r;
		n=r-l+1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long int ans=0,x=1;
		while(true)
		{
			if(l%2==0 && r%2==1)
			{
				l/=2;
				r/=2;
				for(int i=1;i<=n;i++)a[i]/=2;
				x*=2;
				continue;
			}

			for(int i=1;i<=n;i++)
			{
				tag[a[i]]=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(tag[(a[i] xor 1)]==0)
				{
					long long int tmp=0;
					long long int ta;
					if(l%2==1)ta=(l xor a[i]);
					else ta=(r xor a[i]);
					tmp=ch(ta);
					if(tmp==1)
					{
						ans=ta*x;
						break;
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				tag[a[i]]=0;
			}
			break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
