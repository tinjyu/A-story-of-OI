#include <iostream>
#include <algorithm>
using namespace std;
int s[100005],n;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        int mx=n;
        for(int i=1;i<=n;i++)
        {
            if(s[i]!=i-1)
            {
                mx=i-1;
                break;
            }
        }
        cout<<mx<<endl;
        int op=0;
        cin>>op;
        while(op!=-1)
        {
            cout<<op<<endl;
            cin>>op;
        }
        
    }
    return 0;
}