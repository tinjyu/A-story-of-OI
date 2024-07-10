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
long long int n,m,q,k;
long long int x[1000005],w[1000005];

pair<int,int> pa[1000005],ans[1000005];

int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>x[i]>>w[i];
            pa[i].first=w[i];
            pa[i].second=i;
        }
        sort(pa+1,pa+m+1);
        long long int count=0;
        for(int i=1;i<=2*n;i++)
        {
            count+=pa[i].first;
            ans[i].first=x[pa[i].second];
            ans[i].second=pa[i].second;
        }
        sort(ans+1,ans+n*2+1);
        cout<<count<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i].second<<" "<<ans[2*n-i+1].second<<endl;
        }
    }
    return 0;
}