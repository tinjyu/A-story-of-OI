#include <iostream>
using namespace std;
long long int tag[1000005],po[1000005],n,m,k,bits[1000005],pos[1000005],ans[1000005],count;
long long int deg[1000005],map[10000005][2],road[1000005];
string p[1000005],s[1000005];
int build(int a,int b)
{
	if(a==b)return 0;
	count++;
	map[count][0]=b;
	map[count][1]=road[a];
	road[a]=count;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)road[i]=-1;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=m;i++)cin>>s[i]>>po[i];
	for(int i=1;i<=n;i++)
	{
		long long int tmp=0;
		for(int j=0;j<k;j++)
		{
			tmp*=32;
			if(p[i][j]!='_')
			{
				tmp+=(p[i][j]-'a'+1);
			}
		}
		bits[tmp]=i;
	}
	for(int i=1;i<=m;i++)
	{
		long long int tmp=0;
		for(int j=0;j<(1<<k);j++)
		{
			long long int tmp=j,temp=0;
			for(int l=0;l<k;l++)
			{
				temp*=32;
				if(tmp%2==1)
				{
					temp+=(s[i][l]-'a'+1);
				}
				tmp/=2;
			}
			if(bits[temp]!=0)
			{
				build(po[i],bits[temp]);
				//cout<<po[i]<<" "<<bits[temp]<<endl;
				if(po[i]!=bits[temp])deg[bits[temp]]++;
			}
		}
	}
	long long int pp=0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0)
		{
			tag[i]=1;
			pp++;
			ans[pp]=i;
		}
	}
	for(int i=1;i<=pp;i++)
	{
		pos[ans[i]]=i;
		long long int g=road[ans[i]];
		//cout<<ans[i]<<endl;
		while(g!=-1)
		{
			long long int now=map[g][0];
			if(tag[now]==1)
			{
				g=map[g][1];
				continue;
			}
			deg[now]--;
			//cout<<now<<" "<<deg[now]<<endl;
			if(deg[now]==0)
			{
				pp++;
				tag[now]=1;
				ans[pp]=now;
			}
			g=map[g][1];
		}
	}
	//if(m==100000)return 0;

	if(pp!=n)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
	for(int i=1;i<=m;i++)
	{
		//cout<<i<<endl;
		long long int mi=999999999,id=0;
		for(int j=0;j<(1<<k);j++)
		{
			long long int tmp=j,temp=0;
			for(int l=0;l<k;l++)
			{
				temp*=32;
				if(tmp%2==1)
				{
					temp+=(s[i][l]-'a'+1);
				}
				tmp/=2;
			}
			if(bits[temp]!=0)
			{
				//cout<<bits[temp]<<" "<<pos[bits[temp]]<<endl;
				if(pos[bits[temp]]<mi)
				{
					mi=pos[bits[temp]];
					id=bits[temp];
				}
			}
		}
		//cout<<id<<endl;
		if(id!=po[i])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
