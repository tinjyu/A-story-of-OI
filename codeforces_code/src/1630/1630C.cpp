#include <iostream>
#include <algorithm>
using namespace std;
int lpos,rpos,pos,val,tree[10000005],n,a[10000005],dp[10000005],st[1000005],en[1000005],pre[1000005],nxt[1000005];
int change(int s,int e,int t)
{
	if(pos<s || pos>e)return tree[t];
	if(s==e)return tree[t]=val;
	return tree[t]=min(change(s,(s+e)/2,t*2),change((s+e)/2+1,e,t*2+1));
}
int find(int s,int e,int t)
{
	if(lpos>e || rpos<s)return 0;
	if(lpos<=s && e<=rpos)
	{
		val=min(val,tree[t]);
		return 0;
	}
	find(s,(s+e)/2,t*2);
	find((s+e)/2+1,e,t*2+1);
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		st[i]=999999999;
		en[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		st[a[i]]=min(i,st[a[i]]);
		en[a[i]]=max(i,en[a[i]]);
	}
	for(int i=1;i<=n;i++)
	{
		if(en[i]>st[i])
		{
			nxt[st[i]]=en[i];
			pre[en[i]]=st[i];
		}
	}
	long long int ans=n;
	long long int cnt=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]; 
		if(nxt[i]!=0)
		{
			cnt++;
		}
		else if(pre[i]!=0)
		{
			cnt--;
			if(cnt==0)ans--;
			val=9999999999999;
			lpos=pre[i]+1;
			rpos=i-1;
			find(1,n,1);
			dp[i]=val+1;
		}
		else if(cnt==0)ans--;
		pos=i,val=dp[i];
		change(1,n,1);
	}
	cout<<ans-dp[n]<<endl;
}
