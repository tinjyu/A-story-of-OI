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
#include <queue>
using namespace std;
long long int MOD=998244353;
long long int n,m,k,s;
long long int a[1000005],siz[1000004],dis[1000005],tag[1000005];
vector<int> g[1000005];
set<int> val[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        string ans="";
        for(int i=0;i<30;i++)tag[i]=0;
        for(int i=0;i<s.length();i++)
        {
            tag[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(tag[s[i]-'a']==1)
            {
                for(int j=i;j<s.length();j++)cout<<s[j];
                cout<<endl;
                break;
            }
            tag[s[i]-'a']--;
        }
    }
    return 0;
}