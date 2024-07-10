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
char c[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++)c[i]=s[i];
        sort(c,c+s.length());
        for(int i=0;i<s.length();i++)cout<<c[i];
        cout<<endl;
    }
    return 0;
}

