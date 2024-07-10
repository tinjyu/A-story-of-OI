/*

kaaa_kawai

*/


#include <iostream>
#include <map>

using namespace std;

map<string,int> mp;
long long int n,ans[20];
string s[15][10005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        mp.clear();
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>s[i][j];
                mp[s[i][j]]++;
            }
            ans[i]=0;
        }
        
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(mp[s[i][j]]==1)ans[i]+=3;
                if(mp[s[i][j]]==2)ans[i]++;
            }
        }
        cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
    }
    return 0;
}


