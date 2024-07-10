#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n,x,d,t,dp[1000005];
int check(int tmp)
{
	if(tmp%d==0 && (tmp/d)%d!=0)return 0;
	else return 1;
}
int main(){
	cin>>t;
	while(t--)
	{
		cin>>x>>d;
		map<pair<int,int>,int> dp;
		dp[{x,1}]=1;
		long long int ans=0;
		vector<int> del;
		for(int i=1;i*i<=x;i++)
		{
			if(check(i)==0)
			{
				del.push_back(i);
			}
			if(x%i==0 && check(x/i)==0 && x/i!=i)
			{
				del.push_back(x/i);
			}
		}
		while(dp.size())
		{
			auto now=*dp.rbegin();
			if(now.first.first==1)
			{
				ans+=now.second;
			}
			for(int i=0;i<del.size();i++)
			{
				int val=del[i];
				if(now.first.first%val==0 && val>=now.first.second)
				{
					dp[{now.first.first/val,val}]=min(dp[{now.first.first/val,val}]+now.second,2);
				}
			}
			dp.erase(now.first);
		}
		if(ans>=2)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
