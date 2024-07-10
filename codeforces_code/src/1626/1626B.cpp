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
#include <map>

using namespace std;
long long int n,k;
long long int a[1000005],b[1000005];
long long int cnt[1000005];
long long int suf[1000005];
long long int ans[1000005];
char c[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        n=s.length();
        s=" "+s;
        for(int i=1;i<=n;i++)
        {
            a[i]=s[i]-'0';
        }
        int c=0;
        for(int i=n;i>=2;i--)
        {
            if(a[i]+a[i-1]>=10)
            {
                int tmp=a[i]+a[i-1];
                a[i]=tmp-10;
                a[i-1]=1;
                c=1;
                break;
            }
        }
        if(c==0)
        {
            a[2]=a[1]+a[2];
            a[1]=0;
            for(int i=2;i<=n;i++)cout<<a[i];
            cout<<endl;
        }
        else 
        {
            for(int i=1;i<=n;i++)cout<<a[i];
            cout<<endl;
        }
    }
    return 0;
}

