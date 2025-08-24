#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1007,inf=1e9+7;
int n,m;
int a[N][N];//0,1,2
bool vis[N][N];
int d[N][N];
int sx,sy,gx,gy;

priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
void dijkstra(){
	for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
		d[i][j]=d[i+n][j]=inf;
	d[sx][sy]=0;
	q.push({d[sx][sy],{sx,sy}});
	while(!q.empty()){
		int ux=q.top().second.first,uy=q.top().second.second;
		q.pop();
		if(vis[ux][uy])continue;
		vis[ux][uy]=1;
		int tx=ux,ty=uy;
        if(a[ux][uy]==2){
            if(ux<=n)tx+=n;
            else tx-=n;
        }
        if(tx<=n){
            tx--;
            if(1<=tx&&tx<=n&&1<=ty&&ty<=m&&a[tx][ty]!=1&&d[tx][ty]>d[ux][uy]+1){
                d[tx][ty]=d[ux][uy]+1;
                q.push({d[tx][ty],{tx,ty}});
            }
            tx++;
            tx++;
            if(1<=tx&&tx<=n&&1<=ty&&ty<=m&&a[tx][ty]!=1&&d[tx][ty]>d[ux][uy]+1){
                d[tx][ty]=d[ux][uy]+1;
                q.push({d[tx][ty],{tx,ty}});
            }
            tx--;
            ty--;
            if(1<=tx&&tx<=n&&1<=ty&&ty<=m&&a[tx][ty]!=1&&d[tx][ty]>d[ux][uy]+1){
                d[tx][ty]=d[ux][uy]+1;
                q.push({d[tx][ty],{tx,ty}});
            }
            ty++;
            ty++;
            if(1<=tx&&tx<=n&&1<=ty&&ty<=m&&a[tx][ty]!=1&&d[tx][ty]>d[ux][uy]+1){
                d[tx][ty]=d[ux][uy]+1;
                q.push({d[tx][ty],{tx,ty}});
            }
            ty--;
        }
        if(tx>n){
            tx--;
            if(n+1<=tx&&tx<=2*n&&1<=ty&&ty<=m&&a[tx][ty]!=1&&d[tx][ty]>d[ux][uy]+1){
                d[tx][ty]=d[ux][uy]+1;
                q.push({d[tx][ty],{tx,ty}});
            }
            tx++;
            tx++;
            if(n+1<=tx&&tx<=2*n&&1<=ty&&ty<=m&&a[tx][ty]!=1&&d[tx][ty]>d[ux][uy]+1){
                d[tx][ty]=d[ux][uy]+1;
                q.push({d[tx][ty],{tx,ty}});
            }
            tx--;
            ty--;
            if(n+1<=tx&&tx<=2*n&&1<=ty&&ty<=m&&a[tx][ty]!=1&&d[tx][ty]>d[ux][uy]+1){
                d[tx][ty]=d[ux][uy]+1;
                q.push({d[tx][ty],{tx,ty}});
            }
            ty++;
            ty++;
            if(n+1<=tx&&tx<=2*n&&1<=ty&&ty<=m&&a[tx][ty]!=1&&d[tx][ty]>d[ux][uy]+1){
                d[tx][ty]=d[ux][uy]+1;
                q.push({d[tx][ty],{tx,ty}});
            }
            ty--;
        }
	}
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            if(s[j-1]=='.'||s[j-1]=='S'||s[j-1]=='G')a[i][j]=a[i+n][j]=0;
            else if(s[j-1]=='#')a[i][j]=a[i+n][j]=1;
            else if(s[j-1]=='o')a[i][j]=0,a[i+n][j]=1;
            else if(s[j-1]=='x')a[i][j]=1,a[i+n][j]=0;
            else if(s[j-1]=='?')a[i][j]=a[i+n][j]=2;
            if(s[j-1]=='S') sx=i,sy=j;
            else if(s[j-1]=='G') gx=i,gy=j;
            
            //cout<<a[i][j]<<" \n"[j==m];//
        }
    }
    //cout<<sx<<sy<<gx<<gy;//
    // for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    // cout<<a[i+n][j]<<" \n"[j==m];//
    
    dijkstra();
    
    // for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    // cout<<d[i][j]<<" \n"[j==m];//
    // for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    // cout<<d[i+n][j]<<" \n"[j==m];//
    int ans=min(d[gx][gy],d[gx+n][gy]);
    if(ans==inf)cout<<"-1";
    else cout<<ans;
}
