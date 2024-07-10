#include <iostream>
using namespace std;
long long int val[100005],n,a[1005][1005],tag[100005],f[100005],road[250005],map[1000005][3],fa[100005];
int find(int x)
{
	if(f[x]==x)return x;
	else return find(f[x]);
}
int main(){
	cin>>n;
	for(int i=1;i<=50000;i++)
	{
		road[i]=-1;
	}
	long long int count=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(i!=j)
			{
				count++;
				tag[a[i][j]]=1;
				map[count][0]=i;
				map[count][1]=j;
				map[count][2]=road[a[i][j]];
				road[a[i][j]]=count;
			}
		}
		val[i]=a[i][i];
	}
	for(int i=1;i<=50000;i++)f[i]=i;
	long long int cnt=n;
	for(int i=1;i<=5000;i++)
	{		
		

		if(tag[i]==1)
		{
			long long int g=road[i];
			while(g!=-1)
			{
				long long int x=map[g][0],y=map[g][1];
				//cout<<g<<endl;
				if(val[find(x)]!=i && val[find(y)]!=i)
				{
					cnt++;
					val[cnt]=i;
					fa[find(x)]=cnt;
					f[find(x)]=cnt;
					fa[find(y)]=cnt;
					f[find(y)]=cnt;
				}
				else if(val[find(x)]!=i)
				{
					fa[find(x)]=find(y);
					f[find(x)]=find(y);
				}
				else if(val[find(y)]!=i)
				{
					fa[find(y)]=find(x);
					f[find(y)]=find(x);
				}
				g=map[g][2];
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		cout<<val[i]<<" ";
	}
	cout<<endl;
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		if(fa[i]!=0)
		{
			cout<<i<<" "<<fa[i]<<endl;
		}
	}
	
}
