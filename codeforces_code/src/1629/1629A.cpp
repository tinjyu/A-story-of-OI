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
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(k>=a[j])
                {
                    k+=b[j];
                    b[j]=0;
                }
            }
        }
        cout<<k<<endl;
    }
    return 0;
}

