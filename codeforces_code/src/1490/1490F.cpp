#include <iostream>
#include <algorithm>
using namespace std;
long long int n,a[1000005],t,tag[1000005];
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			tag[i]=0;
		}
		sort(a+1,a+n+1);
		long long int ans=99999999999999,cnt=0,sum=0,now=0;
		for(int i=1;i<=n;i++)
		{
			cnt++;
			if(a[i]!=a[i+1])
			{
				tag[cnt]++;
				now+=cnt;
				cnt=0;
				sum++;
			}
			
		}
		
		ans=now;
		for(int i=1;i<=n;i++)
		{
			now-=sum;	
			cout<<now<<" "<<i<<endl;

			ans=min(ans,now);
			sum-=tag[i];
			now+=i*tag[i];
		}
		cout<<ans<<endl;
	}
}
