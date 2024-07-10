/*

kaaa_kawai

*/

#include <iostream>
#include <algorithm>
using namespace std;
long long int q,n,pre[1005][1005],h[100005],w[100005];
string s;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>h[i]>>w[i];
            pre[h[i]][w[i]]+=h[i]*w[i];
        }
        for(int i=1;i<=1000;i++)
        {
            for(int j=1;j<=1000;j++)
            {
                pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }
        while(q--)
        {
            int hs,ws,hb,wb;
            cin>>hs>>ws>>hb>>wb;
            cout<<pre[hb-1][wb-1]-pre[hs][wb-1]-pre[hb-1][ws]+pre[hs][ws]<<endl;
        }
        for(int i=1;i<=1000;i++)
        {
            for(int j=1;j<=1000;j++)pre[i][j]=0;
        }
    }
    return 0;
}
