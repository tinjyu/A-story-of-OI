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
long long int MOD=998244353;
long long int n,m,q;
long long int a[200005],id[1000005],b[1000005],c[1000005];
long long int tree[1000005];
string s,t;
map<int,int> mp;
long long int cnt[1000005];
long long int mi,p;
long long int pre[1004];
long long int dp[10000005];
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
        long long int cnt=2,p=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                p=i;
                break;
            }
        }
        if(p==0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        long long int st=p,pre=p;
        p++;
        if(p>n)p=1;
        int ok=0;
        while(p!=st)
        {
            if(a[p]<2 || a[p]>cnt || a[p]>a[pre]+1)
            {
                ok=1;
                break;
            }
            pre=p;
            cnt++;
            p++;
            if(p>n)p=1;
        }
        if(ok==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}