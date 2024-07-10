#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
struct node{
	long long int num,id;
}t[1000005];
long long int n,k,a[1000005],cnt[1000005];
long long int count(long long int x,long long int num)
{
	long long int sum=0;
	long long int tmp=x%num;
	sum+=(long long int)(x/num)*(long long int)(x/num)*(num-tmp);
	sum+=(long long int)(x/num+1)*(long long int)(x/num+1)*tmp;
	return sum;
}
struct cmp{
	bool operator()(const node &a,const node &b)
	{
		return a.num<b.num;
	}
};
int main(){
	cin>>n>>k;
	long long int p=0;
	long long int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//a[i]=1000000;
		ans+=a[i]*a[i];
		cnt[i]=1;
		if(a[i]>=2)
		{
			p++;
			t[p].num=a[i]*a[i]-count(a[i],2);
			t[p].id=i;
			push_heap(t+1,t+p+1,cmp());
		}
	}
	//cout<<ans<<endl;
	//for(int i=1;i<=n;i++)cout<<t[i].num<<" ";
	//cout<<endl;
	for(long long int i=1;i<=k-n;i++)
	{
		ans-=t[1].num;
		//cout<<t[1].num<<" "<<t[1].id<<endl;
		pop_heap(t+1,t+p+1,cmp());
		cnt[t[p].id]++;
		if(cnt[t[p].id]<=a[t[p].id])
		{
			t[p].num=count(a[t[p].id],cnt[t[p].id])-count(a[t[p].id],cnt[t[p].id]+1);
			push_heap(t+1,t+p+1,cmp());
		}
		else p--;
	}
	cout<<ans<<endl;
} 
