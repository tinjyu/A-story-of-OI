#include <iostream>
#include <map>
using namespace std;
long long int n,m;
map< pair<int,int> ,char>da;
int main(){
	cin>>n>>m;
	long long int c1=0,c2=0;
	for(int i=1;i<=m;i++)
	{
		char t;
		cin>>t;
		if(t=='+')
		{
			int u,v;
			char c;
			cin>>u>>v>>c;
			pair<int,int>r(u,v);
			da[r]=c;
			pair<int,int>r2(v,u);
			if(da.find(r2)!=da.end())
			{
				c1++;
				if(da[r2]==da[r])c2++;
			}
		}
		else if(t=='-')
		{
			int u,v;
			char c;
			cin>>u>>v;
			pair<int,int>r(u,v);
			//date.erase(r);
			pair<int,int>r2(v,u);
			if(da.find(r2)!=da.end())
			{
				c1--;
				if(da[r2]==da[r])c2--;
			}
			da.erase(r);
		}
		else
		{
			int k;
			cin>>k;
			if(k%2==1)
			{
				if(c1>=1)cout<<"YES";
				else cout<<"NO";
			}
			else
			{
				if(c2>=1)
				{
					cout<<"YES";
				}
				else
				{
				 	cout<<"NO";
				}
			}
			cout<<endl;
		}
	}
}
