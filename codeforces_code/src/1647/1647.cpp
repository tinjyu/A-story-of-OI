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
long long int a[1000005],x[1000005],p[1000004],siz[1000004],dis[1000005],tag[1000005],lmx[10000005],rmx[1000005];
long long int lp[1000005],rp[1000005];
long long int tree[1000005][2],lazy[1000005][2];
long long int cnt=0;
long long int mx1=0,mx2=0;
int main(){
    long long int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n%3==0)
        {
            for(int i=1;i<=n/3;i++)cout<<"21";
        }
        else if(n%3==1)
        {
            cout<<"1";
            for(int i=1;i<=n/3;i++)cout<<"21";
        }
        else 
        {
            cout<<"2";
            for(int i=1;i<=n/3;i++)cout<<"12";
        }
        cout<<endl;
    }
    return 0;
}