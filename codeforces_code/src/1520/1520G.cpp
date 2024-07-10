#include <iostream>
using namespace std;
long long int n,m,w,a[2005][2005],st[2005][2005],en[2005][2005],t[4000005][2];
int main(){
	scanf("%lld%lld%lld",&n,&m,&w);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			
			scanf("%lld",&a[i][j]);
		}
	}
	
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			st[i][j]=99999999999999999;
			en[i][j]=99999999999999999;
		}
	}
	long long int p=0,pp=0;
	t[0][0]=1;
	t[0][1]=1;
	st[1][1]=0;
	while(p<=pp)
	{
		long long int x=t[p][0],y=t[p][1];
		for(int i=1;i<=4;i++)
		{
			long long int tmpx=x,tmpy=y;
			if(i==1)tmpx++;
			if(i==2)tmpy++;
			if(i==3)tmpx--;
			if(i==4)tmpy--;
			if(tmpx>=1 && tmpx<=n && tmpy>=1 && tmpy<=m && st[tmpx][tmpy]>st[x][y]+w && a[tmpx][tmpy]!=-1)
			{
				st[tmpx][tmpy]=st[x][y]+w;
				pp++;
				t[pp][0]=tmpx;
				t[pp][1]=tmpy;
			}
		}
		p++;
	}
	p=0;
	pp=0;
	t[0][0]=n;
	t[0][1]=m;
	en[n][m]=0;
	while(p<=pp)
	{
		long long int x=t[p][0],y=t[p][1];
		for(int i=1;i<=4;i++)
		{
			long long int tmpx=x,tmpy=y;
			if(i==1)tmpx++;
			if(i==2)tmpy++;
			if(i==3)tmpx--;
			if(i==4)tmpy--;
			if(tmpx>=1 && tmpx<=n && tmpy>=1 && tmpy<=m && en[tmpx][tmpy]>en[x][y]+w && a[tmpx][tmpy]!=-1)
			{
				en[tmpx][tmpy]=en[x][y]+w;
				pp++;
				t[pp][0]=tmpx;
				t[pp][1]=tmpy;
			}
		}
		p++;
	}
	long long int mi=9999999999999999;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]>0)
			{
				mi=min(mi,en[i][j]+a[i][j]);
			}
		}
	}
	long long int ans=st[n][m];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]>0)
			{
				ans=min(ans,st[i][j]+a[i][j]+mi);
			}
		}
	}
	if(ans>=9999999999999)cout<<"-1";
	else cout<<ans<<endl;
}
