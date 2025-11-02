#include <bits/stdc++.h>
using namespace std;
const int N=110;
int dp[N][N][2],st[N][N][2];
int x,y,p,q;
bool check(int x1,int yy1,int t)
{
    int x2=x-x1;
    int y2=y-yy1;
    if(t==0)
    {
    	if(x2==0)return 1;
        if(y2-x2>q)return false;
        return true;
    }
    else
    {
    	if(yy1==0)return 1;
    	if(x1==0)return 1;
        if(yy1-x1>q)return false;
        return true;
    }
};
void solve()
{
    cin>>x>>y>>p>>q;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<2;k++)
            {
                dp[i][j][k]=0x3f3f3f3f;
            }
        }
    }
    queue<array<int,3>> qq;
    qq.push({x,y,0});
    dp[x][y][0]=0;
    st[x][y][0]=1;

    while(qq.size())
    {
        auto [x1,yy1,t]=qq.front();
        // cout<<x1<<' '<<yy1<<' '<<t<<endl;
        int tt=dp[x1][yy1][t];
        if(x1==0 && t==1)
        {
            cout<<tt<<endl;
            return;
            // break;
        }
        qq.pop();
        for(int i=0;i<=p;i++)
        {
            for(int j=0;j<=p;j++)
            {
                if(i+j>p)continue;
                // if(st[i][j][1-t])continue;
                if(t==0)
                {
                	int xx1=x1-i,yyy1=yy1-j;
                    //printf("%d %d 1:%d:%d\n",x1,yy1,check(x1,yy1,1),tt+1);//
                    if(xx1<0 || yyy1<0)continue;
                    if(st[xx1][yyy1][1])continue;
                    
                    if(check(xx1,yyy1,1))
                    {
                    	//printf("%d %d 1:%d\n",xx1,yyy1,tt+1);//
                        st[xx1][yyy1][1]=1;
                        dp[xx1][yyy1][1]=tt+1;
                        qq.push({xx1,yyy1,1});
                    }
                }
                else
                {
                    int xx1=x1+i,yyy1=yy1+j;
                    if(xx1>x || yyy1>y)continue;
                    if(st[xx1][yyy1][0])continue;
                    
                    if(check(xx1,yyy1,0))
                    {
                    	//printf("%d %d 0:%d\n",xx1,yyy1,tt+1);//
                        st[xx1][yyy1][0]=1;
                        dp[xx1][yyy1][0]=tt+1;
                        qq.push({xx1,yyy1,0});
                    }
                }
            }
        }
    }
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            for(int k=0;k<2;k++)
            {
                //printf("%d %d %d:%d\n",i,j,k,dp[i][j][k]);//
            }
        }
    }
    cout<<-1<<endl;
    // cout<<dp[x][y][0]<<endl;

    // int minzz=0x3f3f3f3f;
    // for(int i=0;i<=y;i++)
    // {
        // if(dp[0][i][1]!=0x3f3f3f3f)
        // {
            // minzz=min(minzz,dp[0][i][1]);
        // }
    // }
    // cout<<minzz<<endl;
}
int main()
{
    //ios::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}