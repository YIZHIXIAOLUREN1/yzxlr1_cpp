#include<bits/stdc++.h>
using namespace std;
#define N 200050
#define ll int
const int inf=0x3f3f3f3f;
int n,m,K;
#define rn(x,y) ((y)*n+(x))
int h[N],to[N],val[N],nxt[N];
ll dis[N];
bool vis[N];
int cnt;

struct node{
	int v;
	ll w;
	friend bool operator <(node a,node b){return a.w>b.w;}
};

void add(int u,int v,int va){
	to[++cnt]=v;
	val[cnt]=va;
	nxt[cnt]=h[u];
	h[u]=cnt;
}

priority_queue<node> q;

void dijkstra(){
	for(int i=1;i<=rn(n,K);i++)
		dis[i]=inf;
	dis[1]=0;
	q.push((node){1,0});
	
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i]){
			if(dis[to[i]]>dis[u]+val[i]){
				dis[to[i]]=dis[u]+val[i];
				q.push((node){to[i],dis[to[i]]});
			}
		}
	}
}


int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1,u,v,w;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        for(int j=0;j<=K;j++){
            add(rn(u,j),rn(v,j),w);
            add(rn(v,j),rn(u,j),w);
        }
        for(int j=0;j<K;j++){
            add(rn(u,j),rn(v,j+1),w/2);
            add(rn(v,j),rn(u,j+1),w/2);
        }
    }
    dijkstra();
    int ans=inf;
    for(int i=0;i<=K;i++){
        ans=min(ans,dis[rn(n,i)]);
    }
    printf("%d",ans);
}
