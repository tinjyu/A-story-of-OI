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
long long int a[1000005],siz[1000004],dis[1000005],tag[1000005];
vector<int> g[1000005];
set<int> val[1000005];
priority_queue <long long int> mx,mi;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        long long int sum=0;
        while(mi.empty()==0)mi.pop();
        while(mx.empty()==0)mx.pop();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mi.push(a[i]);
            sum+=a[i];
        }
        mx.push(sum);
        while(mx.empty()==0)
        {
            long long int x=mx.top(),y=mi.top();
            //cout<<x<<" "<<y<<endl;
            if(x==y)
            {
                mx.pop();
                mi.pop();
            }
            else if(x<y)
            {
                break;
            }
            else 
            {
                mx.pop();
                mx.push((x/2));
                mx.push((x+1)/2);
            }
        }
        if(mi.empty()==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}