#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long int t,x,n,num[1000005],a[1000005],tag[1000005],q,t,st,en;
int main()
{
	cin>>n>>q;
	while(q--)
	{
		cin>>t;
		if(t==0)
		{
			long long int l,r,x;
			cin>>l>>r>>x;
			if(x==0)
			{
				st=l,en=r;
				change(1,n,1);
			}
		}
	}
}
