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
long long int MOD=998244353;
long long int n,m,p,s;
char map[1005][1005];
int main(){
    long long int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        long long int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='1')cnt++;
            }
        }
        if(map[1][1]=='1')
        {
            cout<<"-1"<<endl;
            continue;
        }
        cout<<cnt<<endl;
        for(int i=n;i>=1;i--)
        {
            for(int j=m;j>=1;j--)
            {
                if(map[i][j]=='1')
                {
                    if(i==1)cout<<i<<" "<<j-1<<" "<<i<<" "<<j<<endl;
                    else cout<<i-1<<" "<<j<<" "<<i<<" "<<j<<endl;
                }
            }
        }
    }
    return 0;
}