/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>

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

map<int,int> mp;

int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(mp.find(a[i])==mp.end())
            {  
                mp[a[i]]=1;
            }
            else mp[a[i]]=mp[a[i]]+1;
        }
        for(int i=1;i<=n;i++)
        {
            long long int tmp=0;
            cin>>tmp;
            while(tmp>=1)
            {
                int temp=tmp;
                int ok=0;
                while(temp<=1000000000)
                {
                    if(mp.find(temp)!=mp.end())
                    {
                        //cout<<temp<<endl;
                        int val=(*mp.find(temp)).second;
                        val--;
                        mp.erase(temp);
                        if(val!=0)
                        {
                            mp[temp]=val;
                        }
                        ok=1;
                        break;
                    }
                    else temp*=2;
                }
                if(ok==1)break;
                tmp/=2;
            }
            
        }
        if(mp.empty()==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    } 
    
}
