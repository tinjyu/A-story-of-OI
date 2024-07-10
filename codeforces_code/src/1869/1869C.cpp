#include <iostream>
using namespace std;
long long int n,m;
long long int ans[1000005];

int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        if(m==1)
        {
            cout<<"0"<<endl;
            for(int i=1;i<=n;i++)cout<<"0"<<endl;
            continue;
        }
        int n1,m1;
        if(n<m-1)
        {
            n1=n;
            m1=n+1;
            for(int i=1;i<=n1;i++)
            {
                for(int j=1;j<=m1;j++)
                {
                    ans[i*m+j]=(i+j)%m1;
                }
            }
            for(int i=1;i<=n1;i++)
            {
                for(int j=m1+1;j<=m;j++)
                {
                    ans[i*m+j]=j-1;
                }
            }
        }
        else 
        {
            n1=m-1;
            m1=m;
            for(int i=1;i<=n1;i++)
            {
                for(int j=1;j<=m1;j++)
                {
                    ans[i*m+j]=(i+j)%m1;
                }
            }
            for(int i=n1+1;i<=n;i++)
            {
                for(int j=1;j<=m1;j++)
                {
                    ans[i*m+j]=ans[(i-1)*m+j];
                }
            }
        }
        cout<<m1<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<ans[i*m+j]<<" ";
            }
            cout<<endl;
        }
    }
}