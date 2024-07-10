/*

kaaa_kawai

*/

#include <iostream>
#include <algorithm>
using namespace std;
long long int n,k,r,a[1000005],b[1000005],c[1000005];
int main(){
    int T;
    cin>>T;
    int id=0;
    int temp=T;
    while(T--)
    {
        id++;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            c[i]=0;
        }
        for(int i=1;i<=n;i++)cin>>b[i];

        for(int i=1;i<n;i++)
        {
            if(a[i]<b[i] || c[i]==1)
            {
                if(a[i]<b[i])a[i]=b[i];
                if(a[i+1]<a[i]-1)c[i+1]=1;
                a[i+1]=max(a[i]-1,a[i+1]);
            }
        }
        if(a[n]<b[n] || c[n]==1)
        {
            if(a[n]<b[n])a[n]=b[n];
            a[1]=max(a[n]-1,a[1]);
        }
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=b[i])c=1;
        }
        //if(temp>100)continue;
        
        if(c==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
