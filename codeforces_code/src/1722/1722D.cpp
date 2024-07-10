/*

kaaa_kawai

*/

#include <iostream>
#include <algorithm>
using namespace std;
long long int n,cnt[1000005];
string s;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cin>>s;
        long long int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='L')
            {
                ans+=i;
                cnt[i]=n-i-1-i;
            }
            else 
            {
                ans+=n-i-1;
                cnt[i]=i-n+i+1;
            }
            
        }
        sort(cnt,cnt+n);
        int p=n-1;
        for(int i=1;i<=n;i++)
        {
            if(cnt[p]>0)
            {
                ans+=cnt[p];
                p--;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}
