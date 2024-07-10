#include <iostream>
#include <cstdlib>
using namespace std;
long long int n,m,t,tree[800005],a[1000005],l[1000005][4],cnt[1005],le,ri;
char lazy[1000005],judge[800005],c;
string s[10005],now;
int build(int st,int en,int id)
{
	lazy[id]='A';
	if(st==en)
	{
		judge[id]=s[1][st];
		if(now[st]==s[1][st])tree[id]=1;
		else tree[id]=0;
		return 0;
	}
	build(st,(st+en)/2,id*2);
	build((st+en)/2+1,en,id*2+1);
	
	if(judge[id*2]!=judge[id*2+1])
	{
		judge[id]='A';
	}
	else judge[id]=judge[id*2];
	
	if(tree[id*2]+tree[id*2+1]==2)
	{
		tree[id]=1;
	}
	else tree[id]=0;
	return 0;
}
int pushdown(int st,int en,int id,char ch)
{
	if(ch=='A')return 0;
	lazy[id*2]=ch;
	lazy[id*2+1]=ch;
	if(ch==judge[id*2])tree[id*2]=1;
	else tree[id*2]=0;
	
	if(ch==judge[id*2+1])tree[id*2+1]=1;
	else tree[id*2+1]=0;
	lazy[id]='A';
	return 0;
}
int change(int st,int en,int id)
{
	if(en<le || st>ri)return 0;

	if(le<=st && en<=ri)
	{
		lazy[id]=c;
		if(c==judge[id])
		{
			tree[id]=1;
		}
		else tree[id]=0;
		return 0;
	}
	//cout<<st<<" "<<en<<" "<<id<<" "<<lazy[id]<<endl;
	pushdown(st,en,id,lazy[id]);
	change(st,(st+en)/2,id*2);
	change((st+en)/2+1,en,id*2+1);
	//cout<<tree[id*2]<<" "<<tree[id*2+1]<<endl;
	if(tree[id*2]+tree[id*2+1]==2)
	{
		tree[id]=1;
	}
	else tree[id]=0;
	return 0;
}
string check()
{
	long long int ok=0;
	for(int i=1;i<=3;i++)
	{
		long long int c=0;
		for(int j=0;j<n;j++)
		{
			if(a[j]==0)
			{
				if(s[i][j]!=now[j])
				{
					c=1;
					break;
				}
			}
		}
		if(c==0)ok=1;
	}
	if(ok==0)return "No";
	for(int i=1;i<=3;i++)
	{
		ok=0;
		for(int t=1;t<=3;t++)
		{
			//cout<<cnt[i]<<endl;
			long long int c=0;
			for(int j=1;j<=cnt[i];j++)
			{
				//cout<<l[j][i]<<" "<<s[t][l[j][i]]<<" "<<now[l[j][i]]<<" ";
				if(s[t][l[j][i]]!=now[l[j][i]])
				{
					c=1;
					break;
				}
			}
			//cout<<c<<endl;
			if(c==0)ok=1;
		}
		
		if(ok==0)return "No";
		//cout<<"-----"<<i<<endl;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==3 && now[i]!=s[1][i])
		{
			return "No";
		}
	}
	return "Yes";
}
char find(char s,char e)
{
	if(s=='J' && e=='O')return 'I';
	if(s=='J' && e=='I')return 'O';
	if(s=='O' && e=='J')return 'I';
	if(s=='O' && e=='I')return 'J';
	if(s=='I' && e=='J')return 'O';
	if(s=='I' && e=='O')return 'J';
}
int main(){
	cin>>n;
	cin>>s[1]>>s[2]>>s[3];
	for(int i=0;i<n;i++)
	{
		long long int count=0;
		if(s[1][i]==s[2][i])count++;
		if(s[2][i]==s[3][i])count++;
		if(s[1][i]==s[3][i])count++;
		a[i]=count;
		if(count==1)
		{
			if(s[1][i]==s[2][i])
			{
				cnt[1]++;
				l[cnt[1]][1]=i;
				s[2][i]=find(s[1][i],s[3][i]);
			}
			if(s[1][i]==s[3][i])
			{
				cnt[2]++;
				l[cnt[2]][2]=i;
				s[3][i]=find(s[1][i],s[2][i]);
			}
			if(s[3][i]==s[2][i])
			{
				cnt[3]++;
				l[cnt[3]][3]=i;
				s[2][i]=find(s[1][i],s[2][i]);
			}
		}
	}
	
	//cout<<s[1]<<endl<<s[2]<<endl<<s[3]<<endl;
	long long int q;
	cin>>q;
	cin>>now;
	build(0,n-1,1);
	if(tree[1]==1)
	{
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	while(q--)
	{
		cin>>le>>ri>>c;
		le--;
		ri--;
		change(0,n-1,1);
		if(tree[1]==1)
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
}
