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
long long int n,m,q,k,d,c,w;
long long int ct[1000005],b[1000005],p[1000005];
long long int mi[1000005],x[1000005],y[1000005];
long long int mx[100005];
long long int sg[5000005];
long long int tag1[1000005],tag2[1000005];
long long int sta[1000005][2],top;
string s;
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        long long int hc,dc,hm,dm,a;
        cin>>hc>>dc>>hm>>dm;
        cin>>k>>w>>a;
        long long int c=0;
        for(int i=0;i<=k;i++)
        {
            long long int nowh=hc+i*a,nowd=dc+(k-i)*w;
            if((hm/nowd)+(hm%nowd!=0)<=(nowh/dm)+(nowh%dm!=0))c=1;
        }
        if(c==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}