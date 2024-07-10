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
#include <map>
using namespace std;
long long int n,m,q,k,d;
long long int a[1000005],b[1000005],p[1000005],e[1000005],t[1000005],x[1000005],ans[1000005],w[1000005];
long long int mi[1000005];
long long int dp[100005][105];
long long int tag[1000005];
vector<int> task[1000005];
vector<int> v[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        int now=0;
        for(int i=1;i<=n;i++)
        {
            task[i].clear();
            task[i].push_back(0);
            v[i].clear();
        }
        int cnt=0,pre=1;
        for(int i=1;i<=m;i++)
        {
            tag[i]=0;
            cin>>e[i]>>t[i]>>p[i];
            task[e[i]].push_back(i);
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<task[i].size();j++)
            {
                for(int k=1;k<=100;k++)dp[j][k]=1e18;
                dp[j][0]=0;
            }
            for(int j=1;j<task[i].size();j++)
            {
                int now=task[i][j];
                //cout<<now<<endl;
                for(int k=99;k>=0;k--)
                {
                    int val=min(k+p[now],(long long int)100);
                    dp[j][val]=min(dp[j-1][k]+t[now],dp[j][val]);
                    //if(dp[j][val]<100)cout<<j<<" "<<val<<" "<<dp[j][val]<<endl;
                }
                for(int k=100;k>=0;k--)
                {
                    if(k!=100)dp[j][k]=min(dp[j][k+1],dp[j][k]);
                    dp[j][k]=min(dp[j-1][k],dp[j][k]);
                }
            }
            mi[i]=dp[task[i].size()-1][100];
            int pp=100;
            //cout<<task[i].size()<<endl;
            for(int j=task[i].size()-1;j>=1;j--)
            {
                //cout<<j<<" "<<task[i][j]<<" "<<dp[j][pp]<<endl;
                if(dp[j][pp]!=dp[j-1][pp])
                {
                    pp-=p[task[i][j]];
                    //cout<<task[i][j]<<" "<<pp<<endl;
                    v[i].push_back(task[i][j]);
                }
                if(pp<=0)
                {
                    break;
                }
            }
            //cout<<endl;
        }
        long long int sum=0;
        long long int c=0;
        for(int i=1;i<=n;i++)
        {
            sum+=mi[i];
            //cout<<mi[i]<<" ";
            if(sum>a[i])c=1;
        }
        if(c==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        cout<<m<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                cout<<v[i][j]<<" ";
                tag[v[i][j]]=1;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(tag[i]==0)cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}