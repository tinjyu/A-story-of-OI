#include <iostream>
#include <cmath>
using namespace std;
long long int n,k,a,b,x[1000005],y[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>a>>b;
        for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
        long long int mia=100000000000,mib=10000000000000;
        for(int i=1;i<=k;i++)
        {
            mia=min(mia,abs(x[a]-x[i])+abs(y[a]-y[i]));
            mib=min(mib,abs(x[b]-x[i])+abs(y[b]-y[i]));
        }
        cout<<min(mia+mib,abs(x[a]-x[b])+abs(y[a]-y[b]))<<endl;
    }
}