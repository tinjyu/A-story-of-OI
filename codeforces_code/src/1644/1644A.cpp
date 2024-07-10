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
long long int n,m,q,k,d,t,c;
long long int a[1000005],b[1000005],p[1000005],e[1000005],w[1000005];
long long int mi[1000005];
long long int tag[2000005],dis[2000005],dp[1000005][2];
long long int sum[2000005],cnt[2000005];
long long int ans=0;
string s;
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>s;
        int a=0,b=0,c=0,ok=0;
        for(int i=0;i<6;i++)
        {
            if(s[i]=='r')a=1;
            else if(s[i]=='g')b=1;
            else if(s[i]=='b')c=1;
            else if(s[i]=='R' && a==0)ok=1;
            else if(s[i]=='G' && b==0)ok=1;
            else if(s[i]=='B' && c==0)ok=1;
        }
        if(ok==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}