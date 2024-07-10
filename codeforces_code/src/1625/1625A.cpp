/*

kaaa_kawai

*/

#include <iostream>
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

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>l;
        for(int i=1;i<=n;i++)cin>>a[i];
        long long int ans=0;
        for(int i=0;i<l;i++)
        {
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                if((a[j] & (1<<i))!=0)
                {
                    cnt++;
                }
            }
            cout<<cnt<<endl;
            if(cnt>n/2)ans+=(1<<i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
