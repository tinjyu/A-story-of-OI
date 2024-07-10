/*

kaaa_kawai

*/

#include <iostream>
#include <algorithm>
using namespace std;
long long int n,k,r,c;
char mp[1005][1005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>r>>c;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                mp[i][j]='.';
            }
        }
        long long int now=c%k;
        for(int i=r;i<=n;i++)
        {
            for(int j=now;j<=n;j+=k)mp[i][j]='X';
            now++;
            now%=k;
        }
        now=c%k;
        for(int i=r;i>=1;i--)
        {
            for(int j=now;j<=n;j+=k)mp[i][j]='X';
            now--;
            if(now<0)now+=k;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<mp[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
