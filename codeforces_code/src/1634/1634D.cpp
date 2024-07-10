#include <iostream>
using namespace std;
long long int t,n;

int main(){
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int a=1,b=2,c=3,d=4;
		int cnt=5;
		int re=0;
		while(cnt<=n+2)
		{
			if(a>n)a=re;
			if(b>n)b=re;
			if(c>n)c=re;
			if(d>n)d=re;
			long long int a1,b1,c1,d1;
			cout<<"? "<<d<<" "<<b<<" "<<c<<endl;
			cin>>a1;
			cout<<"? "<<a<<" "<<d<<" "<<c<<endl;
			cin>>b1;
			cout<<"? "<<a<<" "<<b<<" "<<d<<endl;
			cin>>c1;
			cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
			cin>>d1;
			if(a1>=b1 && a1>=c1 && a1>=d1)re=a,a=cnt,cnt++;
			if(b1>=a1 && b1>=c1 && b1>=d1)re=b,b=cnt,cnt++;
			if(c1>=b1 && c1>=a1 && c1>=d1)re=c,c=cnt,cnt++;
			if(d1>=b1 && d1>=c1 && d1>=a1)re=d,d=cnt,cnt++;
		}
		long long int tmp=0,count=0;
		cout<<"! ";
		if(a<=n)
		{
			cout<<a<<" ";
			count++;
			tmp=a;
		}
		if(b<=n)
		{
			cout<<b<<" ";
			count++;
			tmp=b;
		}
		if(c<=n)
		{
			cout<<c<<" ";
			count++;
			tmp=c;
		}
		if(d<=n)
		{
			cout<<d<<" ";
			count++;
			tmp=d;
		}
		if(count==1)cout<<(tmp+1)%n+1<<endl;
		else cout<<endl;
	}
}
