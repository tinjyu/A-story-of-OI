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
long long int p[1000005],a[1000005],b[1000005];
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
        cin>>s>>c;
        int ok=0;
        for(int i=0;i<s.length();i+=2)
        {
            if(s[i]==c)
            {
                ok=1;
            }
        }
        if(ok==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}