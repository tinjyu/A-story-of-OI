/*

kaaa_kawai

*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
#include <ctime>

using namespace std;
long long int MOD=998244353;
long long int n,m,k;
long long int a[1000005],l;
long long int map[1000005][2],road[1000005],deg[100005],ans[1000005];
pair<int,int> pa[1000005];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        long long int ans=-1;
        for(long long int i=1;i<=n;i++)
        {
            cin>>a[i];
            pa[i].first=a[i];
            pa[i].second=i;
        }
        sort(pa+1,pa+n+1);
        for(int i=1;i<n;i++)
        {
            if(pa[i].first!=pa[i+1].first)continue;
            ans=max(pa[i].second+n-pa[i+1].second,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
