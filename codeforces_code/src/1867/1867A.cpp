#include <iostream>
#include <algorithm>
using namespace std;
long long int n,ans[1000005];
int p1,p2,tag[100005];
pair<int,int> a[100005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].first;
            a[i].second=i;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            ans[a[i].second]=n-i+1;
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}