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
long long int n,m,q,k;
long long int p[1000005],a[1000005];
long long int tag[1000005];
long long int nxt[100005][35];
long long int now[1000005];
long long int ans[1000005];

vector<int> node[1000005];

pair<int,int> pa[1000005];

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        a[1]=1;
        long long int c=0;
        for(int i=2;i<=n;i++)
        {
            a[i]=a[i-1]*3;
            if(a[i]>1e9)
            {
                c=1;
                break;
            }
        }
        if(c==1)cout<<"NO"<<endl;
        else 
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}