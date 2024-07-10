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
using namespace std;
long long int MOD=998244353;
long long int n,m,q,k,d,w;
long long int a[1000005],b[1000005],c[1000005],p[1000005];
long long int mi[1000004];
long long int ti[1000005],dp[1000005];
long long int tag[1000005];
string s;
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)tag[i]=0;
        if(n==4 && n-1==k)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(k==n-1)
        {
            cout<<n-1<<" "<<n-2<<endl;
            cout<<"0 2"<<endl;
            cout<<1<<" "<<n-3<<endl;
            tag[n-1]=1;
            tag[n-2]=1;
            tag[0]=1;
            tag[1]=1;
            tag[2]=1;
            tag[n-3]=1;
        }
        else 
        {
            cout<<n-1<<" "<<k<<endl;
            if(k!=0)cout<<0<<" "<<n-1-k<<endl;
            tag[n-1]=1;
            tag[k]=1;
            tag[0]=1;
            tag[n-1-k]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(tag[i]==1)continue;
            cout<<i<<" "<<n-1-i<<endl;
            tag[i]=1;
            tag[n-1-i]=1;
        }
        
    }
    return 0;
}