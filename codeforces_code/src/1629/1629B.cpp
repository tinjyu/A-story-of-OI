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

using namespace std;
long long int n,k;
long long int a[1000005],b[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        long long int l,r;
        cin>>l>>r>>k;
        if(l==r)
        {
            if(l==1)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            continue;
        }
        int cnt=r-l+1-(r/2-(l-1)/2);
        if(cnt<=k)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

