#include<bits/stdc++.h>
using namespace std;
#define MAXN 600000
const int inf=2147483647;
int n,m,s;
int h[MAXN],to[MAXN],val[MAXN],nxt[MAXN];
long long dis[MAXN];
bool vis[MAXN];
int cnt;

struct node{
	int v;
	int w;
	friend bool operator <(node a,node b){
		return a.w>b.w;
	}
} tmp;

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
	tmp.v=s,tmp.w=0;
	q.push(tmp);
	
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i]){
			if(dis[to[i]]>dis[u]+val[i]){
				dis[to[i]]=dis[u]+val[i];
				tmp.w=dis[to[i]],tmp.v=to[i];
				q.push(tmp);
			}
		}
	}
	return;
}


int main(){
	//freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	int u,v,va;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&va);
		add(u,v,va);
	}
	dijkstra();
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	cout << endl; 
	return 0;
}