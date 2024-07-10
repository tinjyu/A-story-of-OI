#include <iostream>
using namespace std;
long long int n,a[100005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n%2==0)
        {
            cout<<"2"<<endl;
            cout<<"1 "<<n<<endl;
            cout<<"1 "<<n<<endl;
        }
        else
        {
            cout<<"4"<<endl;
            cout<<"1 "<<n<<endl;
            cout<<"1 2"<<endl;
            cout<<"2 3"<<endl;
            cout<<"1 "<<n<<endl;
        }
    }
}