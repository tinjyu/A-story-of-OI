#include <iostream>
using namespace std;
long long int n;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
            {
                cnt++;
            }
        }
        for(int i=0;i<=n;i++)
        {
            if(i>=cnt && i<=n-cnt && (n%2==1 || (i-cnt)%2==0))
            {
                cout<<1;
            }
            else cout<<0;
        }
        cout<<endl;
    }
}