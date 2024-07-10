/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>


using namespace std;


string w;
long long int MOD=1000000007;
long long int n,m,q,l,z,k,a[1000005],b[1000005];
long long int road[1000005],u[1000005];
long long int dp[1000005],ans;
long long int cnt[1000005];

long long int nxt[1000005][2];
long long int cunt[1000005];


long long int tag[1000005];

int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int c=0;
        for(int i=1;i<=n;i++)
        {
            nxt[i][0]=0;
            nxt[i][1]=0;
            cunt[i]=0;
            cnt[i]=0;
            tag[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i];
            if(a[i]==b[i])c=1;
            cunt[a[i]]++;
            cunt[b[i]]++;
            if(cnt[a[i]]!=0)
            {
                if(nxt[i][0]==0)nxt[i][0]=cnt[a[i]];
                else nxt[i][1]=cnt[a[i]];
                if(nxt[cnt[a[i]]][0]==0)nxt[cnt[a[i]]][0]=i;
                else nxt[cnt[a[i]]][1]=i;
            }
            else cnt[a[i]]=i;

            if(cnt[b[i]]!=0)
            {
                if(nxt[i][0]==0)nxt[i][0]=cnt[b[i]];
                else nxt[i][1]=cnt[b[i]];
                if(nxt[cnt[b[i]]][0]==0)nxt[cnt[b[i]]][0]=i;
                else nxt[cnt[b[i]]][1]=i;
            }
            else cnt[b[i]]=i;

        }
        
        for(int i=1;i<=n;i++)
        {
            //cout<<i<<" "<<nxt[i][0]<<" "<<nxt[i][1]<<endl;
            if(cunt[i]!=2)c=1;
        }
        if(c==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(nxt[i][1]==0)nxt[i][1]=nxt[i][0];
        }
        for(int i=1;i<=n;i++)
        {
            if(tag[i]==0)
            {
                int now=i,pp=0;
                while(tag[now]==0)
                {
                    tag[now]=1;
                    pp++;
                    if(tag[nxt[now][0]]==0)
                    {
                        now=nxt[now][0];
                    }
                    else if(tag[nxt[now][1]]==0)
                    {
                        now=nxt[now][1];
                    }
                    else break;
                }
                if(pp%2==1)c=1;
            }
        }
        if(c==1)
        {
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
        
    }
    
}
