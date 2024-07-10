/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <map>
using namespace std;
long long int n,l,r;
string s;
long long int a[1000005],b[1000005];
map<int,int> mp;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        long long int ans=0;
        for(int i=30;i>=0;i--)
        {
            mp.clear();
            int temp=ans+(1<<i);
            for(int j=1;j<=n;j++)
            {
                //cout<<(temp & a[j])<<endl;
                mp[(temp & a[j])]++;
            }
            int c=0;
            for(int j=1;j<=n;j++)
            {
                //cout<<(temp xor (b[j] & temp))<<endl;
                if(mp[temp xor (b[j] & temp)]==0)
                {
                    c=1;
                    break;
                }
                mp[temp xor (b[j] & temp)]--;
            }
            if(c==0)
            {
                ans+=(1<<i);
            }
        }
        cout<<ans<<endl;
    }
}
