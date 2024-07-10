#include <iostream>
using namespace std;
long long int n,m,u[1000005],v[1000005],w[1000005],deg[100005],pre[1000005],nxt[1000005],f[1000005],used[1000005],sum,road[1000005],map[1000005][3],t[1000005],dis[1000005][2],mp[805][805];
int qs(int s,int e)
{
	if(s>=e)return 0;
	long long int l=s,r=e,mid=(w[l]+w[r])/2;
	while(l<=r)
	{
		while(w[l]<mid)l++;
		while(w[r]>mid)r--;
		if(l<=r)
		{
			swap(v[l],v[r]);
			swap(u[l],u[r]);
			swap(w[l],w[r]);
			l++;
			r--;
		}
	}
	qs(s,r);
	qs(l,e);
}
int find(int x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)road[i]=-1;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		map[i*2][0]=u[i];
		map[i*2][1]=road[v[i]];
		map[i*2][2]=w[i];
		road[v[i]]=i*2;
		map[i*2+1][0]=v[i];
		map[i*2+1][1]=road[u[i]];
		map[i*2+1][2]=w[i];
		road[u[i]]=i*2+1;
		sum=(sum xor w[i]);
	}
	if(n<=700 && n*(n-1)/2-m<=700)
	{
		long long int ans=9999999999999999;
		for(int i=1;i<=m;i++)
		{
			mp[v[i]][u[i]]=w[i];
			mp[u[i]][v[i]]=w[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				//cout<<mp[i][j]<<endl;
				if(mp[i][j]==0)
				{
					m++;
					v[m]=i;
					u[m]=j;
					w[m]=0;
					//cout<<i<<" "<<j<<endl;
				}
			}
		}
		m++;
		w[m]=sum;
		long long int pos=0;
		qs(1,m);
		for(int i=1;i<=m;i++)
		{
			if(v[i]==0)
			{
				pos==i;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(mp[i][j]==0)
				{			
					long long int x=i,y=j,tmp=0;;
					for(int k=1;k<=n;k++)f[k]=k;
					for(int k=1;k<=m;k++)
					{
						if(v[k]==x && u[k]==y)continue;
						if(v[k]==0)
						{
							v[k]=x;
							u[k]=y;
						}
						//cout<<v[k]<<" "<<u[k]<<" "<<w[k]<<endl;
						if(find(v[k])==find(u[k]))continue;
						f[f[v[k]]]=f[u[k]];
						tmp+=w[k];
					}	
					//cout<<tmp<<endl;
					ans=min(tmp,ans);
				}
			}
		}
		cout<<ans<<endl;
		//ans=999999999999999;
		//cout<<ans<<endl;
		return 0;
	}
	long long int p=0,pp=0;
	t[pp]=1;
	for(int i=0;i<=n+1;i++)
	{
		pre[i]=i-1;
		nxt[i]=i+1;
	}
	nxt[0]=2;
	pre[2]=0;
	long long int ed=0,ans=0;
	for(int i=2;i<=n;i++)
	{
		dis[i][0]=9999999999999999;
	}
	for(int i=1;i<=n;i++)
	{
		long long int x;
		if(p<=pp)
		{
			x=t[p];
			p++;
			ed=1;
		}
		else
		{
			long long int st=nxt[0],tar,mi=99999999999999;
			while(st!=n+1)
			{
				if(dis[st][0]<mi)
				{
					//cout<<st<<" "<<dis[st][0]<<endl;
					mi=dis[st][0];
					tar=st;
				}
				st=nxt[st];
			}
			ans+=mi;
			x=tar;
			nxt[pre[tar]]=nxt[tar];
			pre[nxt[tar]]=pre[tar];
		}
		//cout<<"start:"<<x<<endl;
		long long int g=road[x];
		while(g!=-1)
		{
			long long int now=map[g][0];
			dis[now][0]=min(dis[now][0],map[g][2]);
			dis[now][1]=i;
			g=map[g][1];
		}
		long long int st=nxt[0];
		while(st!=n+1)
		{
			if(dis[st][1]!=i)
			{
				//cout<<st<<endl;
				pp++;
				t[pp]=st;
				nxt[pre[st]]=nxt[st];
				pre[nxt[st]]=pre[st];
			}
			st=nxt[st];
		}
	}
	cout<<ans<<endl;
}
