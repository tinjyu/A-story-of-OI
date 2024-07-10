/*

kaaa_kawai

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
long long int n,l,r;
string s;
long long int a[1000005],b[1000005];
map<int,int> mp;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cin>>s;
        sort(s.begin(),s.end());
        if(s=="Timru")cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
