#include <iostream>
#include <map>
using namespace std;
long long int n,m;
long long int dp[1005][1005];
map<long long int,int> mp;
void dfs(long long int num)
{
    if(mp.find(num)!=mp.end())
    {
        return ;
    }
    mp[num]=mp.size()+1;
    long long int x=1,temp=num;
    while(x<=num)
    {
        temp-=x;
        x*=2;
    }
    long long int num1,num2;
    if(temp<=x/2)
    {
        num1=
    }
}
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        dfs(n);
    }
}