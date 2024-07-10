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
#include <queue>
using namespace std;
long long int MOD=998244353;
long long int n,m,k;
string s;
long long int a[1000005],b[100005],siz[1000004],dis[1000005],pos,cn;
vector<int> g[1000005];
set<int> val[1000005];
long long int ed[1000005];
long long int nd[1000005];
long long int ans=0;
long long int g1[100005],g2=0;
long long int f[1000005];
char mp[1005][1005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mp[i][j];
        }
    }
    int c=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(mp[i][j]=='W' && mp[j][i]!='L')c=1;
            if(mp[i][j]=='L' && mp[j][i]!='W')c=1;
            if(mp[i][j]=='D' && mp[j][i]!='D')c=1;
            
        }
    }
    if(c==1)cout<<"incorrect"<<endl;
    else cout<<"correct"<<endl;
    return 0;
}