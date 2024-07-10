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
long long int n,m,q,k;
long long int a[200005],id[1000005],b[1000005],c[1000005];
long long int tree[1000005];
string s,t;
map<int,int> mp;
long long int cnt[1000005];
long long int mi,p;
long long int pre[1004];
long long int dp[4000005],x[4000005],y[4000005];
long long int ans[2005][2005],v[2005][2005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        cin>>s;
        s=" "+s;
        long long int count=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='1')count++;
        }
        if((count*m)%n!=0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        long long int tar=count*m/n;
        count=0;
        for(int i=1;i<=m;i++)
        {
            if(s[i]=='1')count++;
        }
        long long int en=m;
        for(int i=1;i<=n;i++)
        {
            if(count==tar)
            {
                if(en>=i)
                {
                    cout<<"1"<<endl;
                    cout<<i<<" "<<en<<endl;
                    break;
                }
                else 
                {
                    cout<<"2"<<endl;
                    cout<<"1 "<<en<<endl;
                    cout<<i<<" "<<n<<endl;
                    break;
                }
            }
            en++;
            if(en>n)en=1;
            if(s[en]=='1')count++;
            if(s[i]=='1')count--;
        }

    }
    return 0;
}