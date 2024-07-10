#include <iostream>
using namespace std;
long long int n,t,ans[1000005];
int find(int s,int e,int id,int val)
{
	if(s==e)
	{
		cout<<"! "<<s<<endl;
		ans[id]--;
		return 0;
	}
	if(ans[id*2]==-1 && (s+e)/2>=s)
	{
		cout<<"? "<<s<<" "<<(s+e)/2<<endl;
		long long int tmp;
		cin>>tmp;
		ans[id*2]=(s+e)/2-s+1-tmp;
	}
	if(ans[id*2+1]==-1 && e>=(s+e)/2+1)
	{
		cout<<"? "<<(s+e)/2+1<<" "<<e<<endl;
		long long int tmp;
		cin>>tmp;
		ans[id*2+1]=e-(s+e)/2;
	}
	if(ans[id*2]>=val)
	{
		find(s,(s+e)/2,id*2,val);		
	}
	else
	{
		find((s+e)/2+1,e,id*2+1,val-ans[id*2]);
	}
	ans[id]--;
	return 0;
}
int main(){
	cin>>n>>t;
	for(int i=1;i<=1000000;i++)ans[i]=-1;
	while(t--)
	{
		int val;
		cin>>val;
		find(1,n,1,val);
	}
}
