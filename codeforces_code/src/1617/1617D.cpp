#include <iostream>
using namespace std;
long long int role[1000005],n,T,im,cr,tag[1000005],ans[1000005];
int check(int a,int b,int c)
{
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	int tmp;
	cin>>tmp;
	return tmp;
}
int main(){
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)ans[i]=0;
		for(int i=1;i<=n;i+=3)
		{
			tag[i]=0;
			role[i]=check(i,i+1,i+2);
			if(role[i]==0)im=i;
			else cr=i;
		}
		tag[im]=1;
		tag[cr]=1;
		long long int a1,a2,a3,a4;
		a1=role[im];
		a2=check(im+1,im+2,cr);
		a3=check(im+2,cr,cr+1);
		a4=role[cr];
		if(a2!=a3)
		{
			im=im+1,cr=cr+1;
			if(a2==1)swap(im,cr);
		}
		else if(a3!=a4)
		{
			im=im+2,cr=cr+2;
			if(a3==1)swap(im,cr);
		}
		for(int i=1;i<=n;i+=3)
		{
			if(tag[i]==1)
			{
				if(i!=im && i!=cr)ans[i]=check(im,cr,i);
				if(i+1!=im && i+1!=cr)ans[i+1]=check(im,cr,i+1);
				if(i+2!=im && i+2!=cr)ans[i+2]=check(im,cr,i+2);
			}
			else
			{
				if(role[i]==0)
				{
					int tmp1=check(i,i+1,cr);
					if(tmp1==1)
					{
						ans[i+2]=0;
						ans[i]=check(i,im,cr);
						ans[i+1]=1-ans[i];
					}
					else
					{
						ans[i]=0;
						ans[i+1]=0;
						ans[i+2]=check(cr,im,i+2);
					}
				}
				else
				{
					int tmp1=check(i,i+1,im);
					if(tmp1==0)
					{
						ans[i+2]=1;
						ans[i]=check(i,im,cr);
						ans[i+1]=1-ans[i];
					}
					else
					{
						ans[i]=1;
						ans[i+1]=1;
						ans[i+2]=check(cr,im,i+2);
					}
				}
			}
		}
		ans[im]=0;
		ans[cr]=1;
		int cnt=0;
		cout<<"!"<<" ";
		for(int i=1;i<=n;i++)if(ans[i]==0)cnt++;
		cout<<cnt<<" ";
		for(int i=1;i<=n;i++)if(ans[i]==0)cout<<i<<" "; 
		cout<<endl;
	}
}
