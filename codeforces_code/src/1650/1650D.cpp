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
#include <map>
using namespace std;
long long int n,m,q,k;
long long int a[100005],b[100005],x[1000005],ans[100005],w[1000005];

pair<int,int> pa[1000005];

int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=n;i>=1;i--)
        {
            long long int p=0;
            for(int j=1;j<=i;j++)
            {
                if(a[j]==i)
                {
                    p=j;
                }
            }
            ans[i]=p%i;
            int tmp=i-p;
            for(int j=1;j<=i;j++)
            {
                if(j+tmp>i)
                {
                    b[j+tmp-i]=a[j];
                }
                else b[j+tmp]=a[j];
            }
            for(int j=1;j<=i;j++)a[j]=b[j];
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}