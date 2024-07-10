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

using namespace std;
long long int n,k;
long long int a[1000005],b[1000005];
long long int cnt[1000005];
long long int suf[1000005];
long long int ans[1000005];
string s[1000005];
set<string> st;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        st.clear();
        int c=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            
            if(s[i].length()==1)c=1;
        }
        if(c==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            string tmp="";
            st.insert(s[i]);
            if(s[i].length()==2)
            {
                tmp+=s[i][1];
                tmp+=s[i][0];
                if(st.count(tmp)>=1)c=1;
                for(int j=0;j<26;j++)
                {
                    tmp="";
                    tmp+=s[i][1];
                    tmp+=s[i][0];
                    tmp+=char(j+'a');
                    if(st.count(tmp)>=1)c=1;
                }
                
            }
            else
            {
                tmp="";
                tmp+=s[i][2];
                tmp+=s[i][1];
                tmp+=s[i][0];
                if(st.count(tmp)>=1)c=1;
                tmp="";
                tmp+=s[i][2];
                tmp+=s[i][1];
                if(st.count(tmp)>=1)c=1;
            }
        }
        if(c==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

