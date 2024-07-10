#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int t,n,m,a[1000005],road[1000005],map[1000005][2];
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			road[i]=-1;
		}
		long long int count=0,cnt=0;
		sort(a+1,a+n+1);
		a[n+1]=0;
		for(int i=1;i<=n;i++)
		{
			cnt++;
			if(a[i]!=a[i+1])
			{
				count++;
				map[count][0]=a[i];
				map[count][1]=road[cnt];
				road[cnt]=count;
				cnt=0;
			}
		}
		vector<pair<long long int,long long int>> bad;
		bad.clear();
		
		for(int i=1;i<=m;i++)
		{
			long long int x,y;
			cin>>x>>y;
			bad.push_back(pair<long long int,long long int>{x,y});
			bad.push_back(pair<long long int,long long int>{y,x});
		}
		sort(bad.begin(),bad.end());
		long long int ans=0;
		for(long long int xcnt=1;xcnt<=n;xcnt++)
		{
			long long int px=road[xcnt];
			while(px!=-1)
			{
				long long int x=map[px][0];
				for(long long int ycnt=1;ycnt<=xcnt;ycnt++)
				{
					long long int py=road[ycnt];
					while(py!=-1)
					{
						long long int y=map[py][0];
						if((m==0 || binary_search(bad.begin(),bad.end(),pair<long long int,long long int>(x,y))==0) && x!=y)
						{
							ans=max(ans,(xcnt+ycnt)*(x+y));
							break;
						}
						py=map[py][1];
					}
				}
				px=map[px][1];
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
}
