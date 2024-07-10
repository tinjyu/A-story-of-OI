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
#include <map>

using namespace std;
long long int n;
long long int a[1000005],b[1000005];
long long int cnt[1000005];
long long int suf[1000005];
long long int ans[1000005];
char c[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
        }
        a[n+1]=a[n]+1;
        long long int pre=a[n]+1,nxt=n+1,ans=0;
        for(int i=n;i>=1;i--)
        {
            if(pre>a[i])
            {
                ans+=(a[nxt]-pre+1)*(a[nxt]-pre+2)/2;
                nxt=i;
            }
            pre=min(a[i]-b[i]+1,pre);
        }
        ans+=(a[nxt]-pre+1)*(a[nxt]-pre+2)/2;
        cout<<ans<<endl;
    }
    return 0;
}

