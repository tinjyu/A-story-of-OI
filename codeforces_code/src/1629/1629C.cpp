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

using namespace std;
long long int n,k;
long long int a[1000005],b[1000005];
long long int cnt[1000005];
long long int suf[1000005];
long long int ans[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            cnt[i]=0;
        }
        cnt[n+1]=0;
        long long int now=0,count=0;
        for(int i=n;i>=1;i--)
        {
            cnt[a[i]]++;
            while(cnt[now]!=0)now++;
            suf[i]=now;
        }
        for(int i=0;i<=n+1;i++)cnt[i]=0;
        int p=1;
        while(p<=n)
        {
            now=0;
            int st=p;
            while(true)
            {
                cnt[a[p]]++;
                while(cnt[now]!=0)now++;
                p++;
                if(now==suf[st])break;
            }
            count++;
            ans[count]=now;
            for(int i=0;i<=now;i++)cnt[i]=0;
        }
        cout<<count<<endl;
        for(int i=1;i<=count;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}

