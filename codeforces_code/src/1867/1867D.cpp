#include <iostream>
#include <algorithm>
using namespace std;
long long int n,k,b[1000005];
long long int tag[1000005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            tag[i]=0;
        }
        if(k==1)
        {
            int flag=0;
            for(int i=1;i<=n;i++)
            {
                if(b[i]!=i)flag=1;
            }
            if(flag==1)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            continue;
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(tag[i]==0)
            {
                int p=i;
                while(tag[p]==0)
                {
                    tag[p]=i;
                    p=b[p];
                }
                if(tag[p]!=i)continue;
                int cnt=1,st=p;
                p=b[p];
                while(p!=st)
                {
                    cnt++;
                    p=b[p];
                }
                if(cnt!=k)flag=1;
            }
        }
        if(flag==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}