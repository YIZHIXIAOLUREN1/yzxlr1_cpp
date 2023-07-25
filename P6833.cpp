#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define ll long long
const ll inf=2e15;
int n,m,a,b,c;
int val[N][N];
ll dis[N][N];
ll ba1[N][N],ba2[N][N],ba3[N][N];
bool vis[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

struct node{
	int x,y;
	ll w;
	friend bool operator <(node a,node b){return a.w>b.w;}
}tmp;

priority_queue<node> q;

void dijkstra(int xx,int yy){
	for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
		dis[i][j]=inf;
	dis[xx][yy]=0;
	memset(vis,0,sizeof vis);
	q.push((node){xx,yy,0});
	
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(vis[u.x][u.y]) continue;
		vis[u.x][u.y]=1;
		for(int i=0;i<4;i++){
            int fx=u.x+dx[i],fy=u.y+dy[i];
            if(fx<1||fx>n||fy<1||fy>n)continue;
			if(dis[fx][fy]>dis[u.x][u.y]+val[u.x][u.y]){
				dis[fx][fy]=dis[u.x][u.y]+val[u.x][u.y];
				q.push((node){fx,fy,dis[fx][fy]});
			}
		}
	}
}
ll ans=inf;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> a >> b >> c;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        cin >> val[i][j];
    }
    dijkstra(1,a);
    memcpy(ba1,dis,sizeof dis);
    dijkstra(n,b);
    memcpy(ba2,dis,sizeof dis);
    dijkstra(n,c);
    memcpy(ba3,dis,sizeof dis);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        ans=min(ans,ba1[i][j]+ba2[i][j]+ba3[i][j]+val[i][j]);
    }
    cout << ans;
}
