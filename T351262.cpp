#include<bits/stdc++.h>
using namespace std;
#define N 1050
int n;
bool X[N][N][4];
bool vis[N][N][2];
int ans;
bool check(int x,int y,bool t){
    return y<=x&&x<=n&&x>=1&&y>=1&&(x<n||t==0)&&!vis[x][y][t];
}
void dfs(int x,int y,bool t){
    vis[x][y][t]=1;
    ans++;
    if(t==0){
        if(X[x][y][1]&&check(x-1,y,1))dfs(x-1,y,1);
        if(X[x][y][2]&&check(x,y,1))dfs(x,y,1);
        if(X[x][y][3]&&check(x-1,y-1,1))dfs(x-1,y-1,1);
    }else{
        if(X[x][y][2]&&check(x,y,0))dfs(x,y,0);
        if(X[x+1][y+1][3]&&check(x+1,y+1,0))dfs(x+1,y+1,0);
        if(X[x+1][y][1]&&check(x+1,y,0))dfs(x+1,y,0);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1,x;j<=i;j++){
            scanf("%d",&x);
            if(x==1||x==3||x==5||x==7)X[i][j][1]=1;
            if(x==2||x==3||x==6||x==7)X[i][j][2]=1;
            if(x==4||x==5||x==6||x==7)X[i][j][3]=1;
        }
    }
    dfs(1,1,0);
    printf("%d\n",ans);
}