#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+7;
int n,m,a[N][N];
ll lx[N][N],ly[N][N],lk[N][N],lpk[N][N];

pair<int,int> st[41]={//16
{-3,-1},{-3,1},
{-2,-1},{-2,1},
{-1,-3},{-1,-2},{-1,2},{-1,3},
{1,-3},{1,-2},{1,2},{1,3},
{2,-1},{2,1},
{3,-1},{3,1},
};

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            lx[i][j]=a[i][j]+lx[i-1][j];
            ly[i][j]=a[i][j]+ly[i][j-1];
            lk[i][j]=a[i][j]+lk[i-1][j-1];
            lpk[i][j]=lpk[i-1][j+1]+a[i][j];
        }
    }

    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll res=-3*a[i][j];
            //printf("%d %d:%d %d %d %d:",i,j,lx[n][j],ly[i][m],lk[min(n-i,m-j)+i][min(n-i,m-j)+j],lpk[i+min(n-i,j-1)][j-min(n-i,j-1)]);//
            res+=lx[n][j];
            res+=ly[i][m];
            res+=lk[min(n-i,m-j)+i][min(n-i,m-j)+j];
            res+=lpk[i+min(n-i,j-1)][j-min(n-i,j-1)];
            //printf("%d ",res);//
            for(int k=0;k<16;k++){
                auto [dx,dy]=st[k];
                if(i+dx>=1&&i+dx<=n&&j+dy>=1&&j+dy<=m)res+=a[i+dx][j+dy];
            }
            //printf("%d\n",res);//
            ans=max(ans,res);
        }
    }
    cout<<ans;
}
/*
    x
   oxo
  xoxox
 ooxxxoo
xxxxxxxxx
 ooxxxoo
  xoxox
   oxo
    x

*/