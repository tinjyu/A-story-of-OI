#include <iostream>
using namespace std;
long long int t,n,k,num[10005],tag[100005],len;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long int ans=n;
		len=0;
		for(int i=0;i<=10;i++)tag[i]=0;
		while(n>0)
		{
			num[len]=n%10;
			n/=10;
			len++;
		}
		if(k==1)
		{
			long long int ma=num[len-1];
			for(int i=len-2;i>=0;i--)
			{
				if(ma>num[i])break;
				if(ma<num[i])
				{
					ma++;
					break;
				}
			}
			for(int i=1;i<=len;i++)cout<<ma;
			cout<<endl;
			continue;
		}
		long long int cnt=0;
		for(int i=len-1;i>=0;i--)
		{
			if(tag[num[i]]==0)
			{
				cnt++;	
			}
			tag[num[i]]++;
			if(cnt>k)
			{
				for(int j=i;j<len;j++)
				{
					
					if(cnt<k || (cnt==k && tag[num[j]]==1))
					{
						tag[num[j]]--;
						if(tag[num[j]]==0)cnt--;
						num[j]++;
						if(tag[num[j]]==0)cnt++;
						tag[num[j]]++;
						long long int mi;
						for(int k=0;k<=9;k++)
						{
							if(tag[k]!=0)
							{
								mi=k;
								break;
							}
						}
						if(cnt<k)mi=0;
						for(int k=0;k<j;k++)
						{
							num[k]=mi;
						}
						ans=0;
						for(int i=len-1;i>=0;i--)
						{
							ans=ans*10+num[i];
						}
						break;
					}
					else
					{
						int ok=0;
						for(int k=0;k<=9;k++)
						{
							if(tag[k]!=0 && k>num[j])
							{
								if(tag[num[j]]==1)cnt--;
								tag[num[j]]--;
								num[j]=k;
								tag[num[j]]++;
								ok=1;
								break;
							}
						}
						if(ok==1&&cnt<=k)
						{
							long long int mi;
							for(int k=0;k<=9;k++)
							{
								if(tag[k]!=0)
								{
									mi=k;
									break;
								}
							}
							if(cnt<k)mi=0;
							for(int k=0;k<j;k++)
							{
								num[k]=mi;
							}
							ans=0;
							for(int i=len-1;i>=0;i--)
							{
								ans=ans*10+num[i];
							}
							break;
						}
					}
					if(tag[num[j]]==1)cnt--;
					tag[num[j]]--;
				}
				
				break;
			}
		}
		cout<<ans<<endl;
	}
}
