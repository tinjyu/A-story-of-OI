#include <iostream>
using namespace std;
long long int n,k;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        long long int l=1,ans=0;
        while(l+k-1<=n)
        {
            cout<<"? "<<l<<endl;
            int temp;
            cin>>temp;
            ans=ans ^ temp;
            l+=k;
        }
        int rem=n-l+1;
        if(rem==k)
        {
            cout<<"? "<<l<<endl;
            int temp;
            cin>>temp;
            ans=ans ^ temp;
        }
        else 
        {
            l-=(2*k-rem)/2;
            cout<<"? "<<l<<endl;
            int temp;
            cin>>temp;
            ans=ans ^ temp;
            l=n-k+1;
            cout<<"? "<<l<<endl;
            cin>>temp;
            ans=ans ^ temp;
        }
        cout<<"! "<<ans<<endl;
    }
}