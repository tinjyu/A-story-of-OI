/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <ctime>
#include <queue>
#include <map>
using namespace std;
long long int MOD=1000000007;
long long int n,m,q,k,d,s,t,c;
long long int a[1000005],b[1000005],p[1000005],e[1000005],ans[1000005],w[1000005];
long long int mi[1000005];
long long int tag[2000005],dis[2000005],dp[1000005][2];
long long int sum[2000005],cnt[2000005];
vector<long long int> x[1000005],y[1000005];
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        

        cin>>n>>c;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            cnt[a[i]]=1;
        }
        n=0;
        for(int i=1;i<=c;i++)
        {
            if(cnt[i]==1)
            {
                n++;
                a[n]=i;
            }
        }
        for(int i=1;i<=2*c;i++)sum[i]=sum[i-1]+cnt[i];
        int ok=1;
        for(int i=1;i<=c;i++)
        {
            if(cnt[i]>=1)continue;
            for(int j=1;j<=n;j++)
            {
                if(i*a[j]>c)break;
                long long int tmp=i*a[j];
                if(sum[tmp+a[j]-1]-sum[tmp-1]>0)ok=0;
            }
        }
        if(ok==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for(int i=1;i<=c*2;i++)
        {
            sum[i]=0;
            cnt[i]=0;
        }
    }
    return 0;
}