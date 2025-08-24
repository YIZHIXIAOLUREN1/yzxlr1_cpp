#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n,m,Q;
int a[N][N];
bool vis[N][N];
int ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>Q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }

    while(Q--){
        int x,y;
        cin>>x>>y;
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        ans=0;
        while(1){
            ans++;
            if(a[x][y]==1)x--;
            else if(a[x][y]==2)x++;
            else if(a[x][y]==3)y--;
            else y++;
            if(x==0||x==n+1||y==0||y==m+1){
                cout<<ans<<"\n";break;
            }else if(vis[x][y]){cout<<"-1\n";break;}
            vis[x][y]=1;
        }
    }
}
