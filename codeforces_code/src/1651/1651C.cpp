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
long long int p[1000005],a[1000005],b[1000005];
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
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
        }
        long long int ans=999999999999999;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                long long int sum=0;
                tag[1]=0;
                tag[n]=0;
                if(i==1)
                {
                    sum+=abs(a[1]-b[1]);
                    tag[1]=1;
                }
                if(i==2)
                {
                    sum+=abs(a[1]-b[n]);
                    tag[n]=1;
                }
                if(i==3)
                {
                    long long int mi=9999999999999999;
                    for(int k=1;k<=n;k++)
                    {
                        mi=min(abs(a[1]-b[k]),mi);
                    }
                    sum+=mi;
                }
                if(j==1)
                {
                    sum+=abs(a[n]-b[1]);
                    tag[1]=1;
                }
                if(j==2)
                {
                    sum+=abs(a[n]-b[n]);
                    tag[n]=1;
                }
                if(j==3)
                {
                    long long int mi=9999999999999999;
                    for(int k=1;k<=n;k++)
                    {
                        mi=min(abs(a[n]-b[k]),mi);
                    }
                    sum+=mi;
                }

                if(tag[1]==0)
                {
                    long long int mi=9999999999999999;
                    for(int k=1;k<=n;k++)
                    {
                        mi=min(abs(b[1]-a[k]),mi);
                    }
                    sum+=mi;
                }
                if(tag[n]==0)
                {
                    long long int mi=9999999999999999;
                    for(int k=1;k<=n;k++)
                    {
                        mi=min(abs(b[n]-a[k]),mi);
                    }
                    sum+=mi;
                }
                ans=min(ans,sum);

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}