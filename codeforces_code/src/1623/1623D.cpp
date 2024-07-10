#include <iostream>
using namespace std;
long long int n,m,rb,cb,rd,cd,p,tag[1000005][10],tag2[10000005],t,q;
long long int exp(long long int a,long long int b)
{
	long long int ans=1,x=a;
	while(b>0)
	{
		if(b%2==1)ans*=x;
		ans%=1000000007;
		x*=x;
		x%=1000000007;
		b/=2;
		
	}
	return ans;
}
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>rb>>cb>>rd>>cd>>p;
		q=100-p;
		int dr=1,dc=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=0;k<=5;k++)
				{
					tag[i*m+j][k]=0;
					tag2[i*m+j]=0;
				}
			}
		}
		
		if(rb+dr>n || rb+dr<1)dr*=-1;
		if(cb+dc>m || cb+dc<1)dc*=-1;
		int loc=max(dr,0)*2+max(dc,0);
		tag[rb*m+cb][loc]=1;
		long long int num=0;
		if(rb==rd || cb==cd)
		{
			num++;
			tag2[rb*m+cb]=1;
		}
		long long int ti=1;
		while(true)
		{
			
			ti++;
			rb+=dr;
			cb+=dc;
			if(rb+dr>n || rb+dr<1)dr*=-1;
			if(cb+dc>m || cb+dc<1)dc*=-1;
			loc=max(dr,0)*2+max(dc,0);
			
			if(tag[rb*m+cb][loc]==0)
			{
				tag[rb*m+cb][loc]=ti;
			}
			else break;
			
			if(rb==rd || cb==cd)
			{
				num++;
				tag2[rb*m+cb]=num;
			}
		}
		long long int R=ti-1;
		cout<<R<<endl;
		long long int ansp=0;
		long long int temp1=abs(exp(100,num)-exp(q,num))%1000000007;
		for(int i=1;i<=n;i++)
		{
			for(int k=0;k<4;k++)
			{
				if(tag[i*m+cd][k]!=0)
				{
					long long int T=tag[i*m+cd][k],K=tag2[i*m+cd];
					ansp+=p%1000000007*T%1000000007*exp(q,K-1)%1000000007*exp(100,num-K)%1000000007*temp1%1000000007;
					ansp%=1000000007;
					//cout<<ansp<<endl;
					ansp+=R*exp(q,K+num-1)%1000000007*p%1000000007*exp(100,num-K)%1000000007;
					ansp%=1000000007;
					//cout<<ansp<<endl;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<4;k++)
			{	
				if(j==cd)continue;
				if(tag[rd*m+j][k]!=0)
				{	
					
					long long int T=tag[rd*m+j][k],K=tag2[rd*m+j];
					ansp+=p%1000000007*T%1000000007*exp(q,K-1)%1000000007*exp(100,num-K)%1000000007*temp1%1000000007;
					ansp%=1000000007;
					//cout<<ansp<<endl;
					ansp+=R*exp(q,K+num-1)%1000000007*p%1000000007*exp(100,num-K)%1000000007;
					ansp%=1000000007;
					//cout<<ansp<<endl;
				}
			}
		}
		ansp-=temp1*temp1%1000000007;
		if(ansp<0)ansp+=1000000007;
		
		cout<<ansp*exp(temp1*temp1%1000000007,1000000005)%1000000007<<endl;
	}
}
