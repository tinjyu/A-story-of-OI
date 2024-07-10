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
long long int n,m,q,k,d;
long long int p[1000005],b[1000005];
long long int x[1000005],y[1000005];
long long int tag[1000005];
long long int now[1000005];
long long int step[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
long long int t[1000005],pp;

long long int cyc[1000005],cnt;
long long int ans=0;
string s;
char c;

int main(){
    int T;
    cin>>T;
    while(T--)
    {
        long long int l,r,a;
        cin>>l>>r>>a;
        if(r%a==a-1)cout<<r/a+r%a<<endl;
        else if((r/a)*a-1>=l)cout<<r/a+a-2<<endl;
        else cout<<r/a+r%a<<endl;
    }
    return 0;
}