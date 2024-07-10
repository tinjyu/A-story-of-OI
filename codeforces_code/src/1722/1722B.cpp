/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
long long int n,l,r;
string s,t;
long long int a[1000005],b[1000005];
map<int,int> mp;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cin>>s>>t;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if((s[i]=='R' && t[i]=='G') || (s[i]=='R' && t[i]=='B') || (s[i]=='G' && t[i]=='R') || (s[i]=='B' && t[i]=='R'))c=1;
        }
        if(c==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
