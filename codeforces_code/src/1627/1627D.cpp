#include <iostream>
#include <cmath>
#include <algorithm> 
#include <set>
using namespace std;
long long int sum[1000005],n,m,k,t,a[1000005],b[100005],p;
long long int tmp[1000005],map[505][505][4];
long long int tag[1000005];
string s[100005];

int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	cin>>n;
	long long int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tag[a[i]]=1;
	}
	for(int i=1;i<=1000000;i++)
	{
		long long int now=0;
		for(int j=i;j<=1000000;j+=i)
		{
			if(tag[j]==1)
			{
				now=gcd(j,now);
			}
		}
		if(now==i)cnt++;
	}
	cout<<cnt-n;
}
