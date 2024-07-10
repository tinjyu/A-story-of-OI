/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;
long long int MOD=998244353;
long long int n,m,k;
long long int a[1000005],id[1000005],b[1000005];
long long int cnt[30][30],sum[1000005];
long long int dp[1000005];
long long int f[1000005],c;
vector<long long int> mp[1000005];
string s;
pair<long long int,long long int> pa[1000005];


int main(){
    int T;
    cin>>T;
    while(T--)
    {
        int x,y;
        cin>>n>>x>>y;
        int len=x/(y+1),add=x%(y+1);
        for(int i=1;i<=add;i++)
        {
            for(int j=1;j<=len+1;j++)cout<<"R";
            cout<<"B";
        }
        for(int i=add+1;i<=y;i++)
        {
            for(int j=1;j<=len;j++)cout<<"R";
            cout<<"B";
        }
        for(int i=1;i<=len;i++)cout<<"R";
        cout<<endl;
    }
}
