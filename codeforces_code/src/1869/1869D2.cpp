#include <iostream>
using namespace std;
long long int n,a[1000005];
long long int tag[10005],cnt1[10005],cnt2[10005];
int main(){
    int id=0;
    int T;
    int tmp=0;
    cin>>T;
    tmp=T;
    while(T--)
    {
        id++;
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
        for(int i=0;i<=40;i++)tag[i]=0,cnt1[i]=0,cnt2[i]=0;
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
            if(en==st+1)
            {
                if(avg>a[i])cnt1[st]++;
                else cnt2[st]--;
            }
            else if(avg>a[i])
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
        for(int i=40;i>=1;i--)
        {
            if(tag[i]<0)
            {
                if(cnt1[i-1]<-tag[i])flag=1;
                int temp=-tag[i];
                tag[i-1]-=temp;
                tag[i-1]+=cnt1[i-1]-temp;
                tag[i-1]+=cnt2[i-1];
                tag[i]=0;
            }
            else if(tag[i]>0)
            {
                if(-cnt2[i-1]<tag[i])flag=1;
                int temp=tag[i];
                tag[i-1]+=temp;
                tag[i-1]-=-cnt2[i-1]-temp;
                tag[i-1]+=cnt1[i-1];
                tag[i]=0;
            }
            else tag[i-1]+=cnt1[i-1]+cnt2[i-1];
        }
        if(tag[0]!=0)flag=1;
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else 
        {
            cout<<"YES"<<endl;
        }
    }
}