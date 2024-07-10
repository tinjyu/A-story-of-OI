#include <iostream>
#include <cmath>
using namespace std;
long long int n,a[1000005],cnt[60000005];
long long int map[10000005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//a[i]=(n-i)*100+2;
	}

	long long int len=sqrt(100000);
	//cout<<len<<endl;
	long long int ans=0;
	for(long long int i=1;i<=len;i++)
	{
		//cout<<i<<endl;
		int sum=0;
		for(long long int j=1;j<=n;j++)
		{
			cnt[a[j]+i*j]++;
			ans=max(ans,cnt[a[j]+i*j]);
		}
		for(long long int j=1;j<=n;j++)
		{
			cnt[a[j]+i*j]=0;
		}
		for(long long int j=1;j<=n;j++)
		{
			cnt[a[j]+i*(n-j)]++;
			ans=max(ans,cnt[a[j]+i*(n-j)]);
		}
		for(long long int j=1;j<=n;j++)
		{
			cnt[a[j]+i*(n-j)]=0;
		}
	}
	//cout<<"ok"<<endl;
	int now=1,pre=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<endl;
		for(int j=i-1;j>=max((long long int)1,i-len-10);j--)
		{
			if((a[i]-a[j])%(i-j)==0)
			{
				cnt[(a[i]-a[j])/(i-j)+500005]++;
				//cout<<a[i]<<" "<<a[j]<<" "<<i<<" "<<j<<" "<<cnt[(a[i]-a[j])/(i-j)+500005]<<" "<<(a[i]-a[j])/(i-j)<<endl;
				ans=max(cnt[(a[i]-a[j])/(i-j)+500005]+1,ans);
			}
		}
		for(int j=i-1;j>=max((long long int)1,i-len-10);j--)
		{
			if((a[i]-a[j])%(i-j)==0)
			{
				cnt[(a[i]-a[j])/(i-j)+500005]=0;
			}
		}
		
	}
	cout<<n-ans<<endl;
} 
