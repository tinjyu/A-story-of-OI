/*

kaaa_kawai

*/

#include <iostream>
#include <algorithm>
using namespace std;
long long int MOD=1e9+7;
long long int n,k,r,a[1000005],b[1000005],c[1000005];
long long int per[1000004],nper[1000005];
int main(){
    int T;
    //cin>>T;
    int id=0;
    T=1;
    while(T--)
    {
        cin>>n>>k;
        k=min(n,k);
        long long int ans=0;
        per[0]=1;
        nper[0]=1;
        for(int i=1;i<=n;i++)
        {
            per[i]=per[i-1]*i;
            per[i]%=1000000000+7;
            nper[i]=1;
            long long int x=per[i],temp=1000000005;
            while(temp>0)
            {
                if(temp%2==1)nper[i]*=x;
                x*=x;
                x%=MOD;
                nper[i]%=MOD;
                temp/=2;
            }
        }
        for(int i=0;i<=k;i++)
        {
            ans+=(per[n]*nper[i]%MOD)*nper[n-i];
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
