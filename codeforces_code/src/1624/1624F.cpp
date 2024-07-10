#include <iostream>
#include <algorithm>
using namespace std;
long long int n,ans,req[10005];
int main(){
	cin>>n;
	long long int l=0,r=n-1,p=0;
	long long int ad=0;
	long long int pp=1;
	req[0]=0;
	while(l<r)
	{
		//cout<<l<<" "<<r<<" "<<ad<<endl;
		long long int mid=(l+r)/2+1;
		cout<<"+ "<<(2*n-mid-ad%n-1)%n+1<<endl;
		ad+=(2*n-mid-ad%n)%n;
		cin>>req[pp];
		if(req[pp]>req[pp-1])
		{
			l=mid;
			p=mid;
		}
		else 
		{
			r=mid-1;
			p=mid-1;
		}
	
		pp++;
	}
	cou<<"! "<<t<<p<<endl;
}
