#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
long long int n,m,k,dp[505][505],t,a[1000005];
long long int tmp[1000005],map[505][505][4];
inline int read(){
    register int x = 0, t = 1;
    register char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            t=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*t;
}
int main(){
	t=read();
	while(t--)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			tmp[i]=a[i];
		}
		sort(tmp+1,tmp+n+1);
		long long int x=1,y=n,num=(n-k+1)/2+k;
		cout<<num<<endl;
		for(int i=1;i<=n-num+1;i++)
		{
			if(tmp[i+num-1]-tmp[i]<y-x)
			{
				y=tmp[i+num-1];
				x=tmp[i];
			}
		}
		cout<<x<<" "<<y<<endl;
		long long int cnt=0;
		int pre=1;
		num=0;
		for(int i=1;i<=n;i++)
		{
			if(num==k-1)break;
			if(a[i]<=y && a[i]>=x)
			{
				cnt++;
			}
			else cnt--;
			if(cnt>0)
			{
				cnt=0;
				printf("%d %d \n",pre,i);
				pre=i+1;
				num++;
			}
		}
		printf("%d %lld \n",pre,n);
	}
	
} 
