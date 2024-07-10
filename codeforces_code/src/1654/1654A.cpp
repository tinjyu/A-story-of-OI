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
long long int n,m,k,s;
long long int a[1000005],siz[1000004],dis[1000005];
vector<int> g[1000005];
set<int> val[1000005];
long long int ans=0;
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
        long long int ma1=0,ma2=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=ma1)
            {
                ma2=ma1;
                ma1=a[i];
            }
            else if(a[i]>=ma2)ma2=a[i];
        }
        cout<<ma1+ma2<<endl;
    }
    return 0;
}