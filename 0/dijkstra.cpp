#include<bits/stdc++.h>
using namespace std;
#define MAXN 300000
#define pr pair<int,int>
const int inf=2147483647;
int n,m,s;
int dis[MAXN],h[MAXN],to[MAXN],val[MAXN],nxt[MAXN];
bool vis[MAXN];
int cnt;
void add(int u,int v,int va){
	to[++cnt]=v;
	val[cnt]=va;
	nxt[cnt]=h[u];
	h[u]=cnt;
}

priority_queue<pr> q;

int dijkstra(){
	for(int i=1;i<=n;i++)
		dis[i]=inf;
	dis[s]=0;
	dis[0]=inf;
	q.push({s,dis[s]});
	while(!q.empty()){
		int u=q.top().first;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i]){
			dis[to[i]]=min(1ll*dis[to[i]],1ll*dis[u]+val[i]);
			if(1ll*dis[u]+val[i]<dis[to[i]]){
				dis[to[i]]=1ll*dis[u]+val[i];
				q.push({to[i],dis[to[i]]});
			}
		}
		
	}
}


int main(){
	scanf("%d%d%d",&n,&m,&s);
	int u,v,va;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&va);
		add(u,v,va);
	}
	dijkstra();
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;
}
