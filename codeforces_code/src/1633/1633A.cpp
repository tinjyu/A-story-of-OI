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
long long int n,m,q,k,d,c;
long long int ct[1000005],a[1000005],b[1000005],p[1000005],e[1000005],w[1000005];
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
        cin>>n;
        if(n%7==0)
        {
            cout<<n<<endl;
            continue;
        }
        for(int i=(n/10)*10;i<(n/10)*10+10;i++)
        {
            if(i%7==0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}