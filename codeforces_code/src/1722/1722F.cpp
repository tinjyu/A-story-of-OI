/*

kaaa_kawai

*/

#include <iostream>
#include <algorithm>
using namespace std;
long long int q,n,m,tag[505][505],cnt,tx[100005],ty[100005];
string s;
long long int step[10][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
char mp[505][505];
void find(int x,int y)
{
    cnt++;
    tx[cnt]=x;
    ty[cnt]=y;
    tag[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int tempx=x+step[i][0],tempy=y+step[i][1];
        if(tempx<=n && tempy<=m && tempx>=1 && tempy>=1 && tag[tempx][tempy]==0 && mp[tempx][tempy]=='*')
        {
            find(tempx,tempy);
        }
    }
    return ;
}
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
                tag[i][j]=0;
            }
        }
        int c=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(tag[i][j]==0 && mp[i][j]=='*')
                {
                    cnt=0;
                    find(i,j);
                    if(cnt!=3)
                    {
                        c=1;
                        break;
                    }
                    int temp=0;
                    if(tx[2]==tx[1]+1 && ty[2]==ty[1] && tx[3]==tx[1]+1 && ty[3]==ty[1]+1)temp=1;
                    if(tx[2]==tx[1]+1 && ty[2]==ty[1] && tx[3]==tx[1]+1 && ty[3]==ty[1]-1)temp=1;
                    if(tx[2]==tx[1] && ty[2]==ty[1]+1 && tx[3]==tx[1]+1 && ty[3]==ty[1]+1)temp=1;
                    if(tx[2]==tx[1] && ty[2]==ty[1]+1 && tx[3]==tx[1]+1 && ty[3]==ty[1])temp=1;
                    if(temp==0)c=1;
                }
            }
        }
        if(c==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
