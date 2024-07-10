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


string s,t;
long long int MOD=1000000007;
long long int n,m,q,l,z;
long long int road[1000005];
long long int map[1000005][3];
pair<long long int,long long int> vec[1000005];
char mp[1000005];
long long int in[1000005],out[1000005];
long long int dp[1000005],ans;
long long int tag[100005];
int main(){
    int T;
    cin>>T;
    dp[0]=1;
    while(T--)
    {
        long long int m=0;
        cin>>m;
        int now=1;
        for(int i=1;i<=100;i++)
        {  
            if(now*10>m)
            {
                cout<<m-now<<endl;
                break;
            }
            
            now*=10;
        }
    }
    
}
