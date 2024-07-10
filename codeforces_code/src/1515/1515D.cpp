#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
long long int d,x,n,t,lsocks[1000005],rsocks[1000005],a,b,tmpl[1000005],tmpr[1000005];
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n>>d>>x;
		long long int sum=0;
		for(int i=1;i<=n;i++)
		{
			long long int tmp;
			cin>>tmp;
			sum+=tmp;
			sum%=2;
		}
		sum=abs(sum);
		if(abs(d-x)%2==sum)
		{
			cout<<"Alice"<<endl;
		}
		else cout<<"Bob"<<endl;
	
	}
} 
