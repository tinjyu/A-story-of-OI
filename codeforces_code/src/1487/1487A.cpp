#include <iostream>
using namespace std;
long long int ans,mi,t,n,a[100005];

int main(){
	cin>>t;
	while(t--)
	{
		cin>>n;
		mi=999999999999;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			mi=min(a[i],mi);
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=mi)ans++;
		}
		cout<<ans<<endl;
	}
}
