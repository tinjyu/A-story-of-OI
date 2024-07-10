#include <iostream>
using namespace std;
long long int n,a[1000005];
long long int tag[10005];
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        long long int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%n!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        long long int avg=sum/n,flag=0;
        for(int i=0;i<=40;i++)tag[i]=0;
        for(int i=1;i<=n;i++)
        {
            int temp=abs(avg-a[i]);
            int st=-1,en=-1,p=0;
            while(temp>0)
            {
                if(temp%2==1)
                {
                    if(st==-1)st=p;
                }
                else
                {
                    if(st!=-1)flag=1;
                }
                p++;
                temp/=2;
            }
            en=p;
            if(st==-1)st=0;
            if(avg>a[i])
            {
                tag[st]--;
                tag[en]++;
            }
            else 
            {
                tag[st]++;
                tag[en]--;
            }
        }
        for(int i=0;i<=40;i++)
        {
            if(tag[i]!=0)flag=1;
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
}