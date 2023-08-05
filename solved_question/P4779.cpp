#include<bits/stdc++.h>
using namespace std;
#define N 300000
#define ll long long
const int inf=2147483647;
int n,m,s;
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
	for(int i=1;i<=n;i++)
		dis[i]=inf;
	dis[s]=0;
	q.push((node){s,0});
	
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
