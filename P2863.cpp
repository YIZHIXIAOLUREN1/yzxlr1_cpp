#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int n,m;
int h[maxn],nxt[maxn],to[maxn];
int cntt;
int dfn[maxn],low[maxn];
bool vis[maxn];

void add(int u,int v){
	nxt[++cntt]=h[u];to[h[u]=cntt]=v;
}

int st[maxn],top,cnt,idx,siz[maxn],bel[maxn];
bool ins[maxn];
void dfs(int u){
	low[u]=dfn[u]=++cnt;
	ins[st[++top]=u]=1;
	for(int i=h[u];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		} else if(ins[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		int v;++idx;
		do{
			v=st[top--];
			bel[v]=idx;
			ins[v]=0;
			++siz[idx];
		}while(v!=u);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;++i){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]) dfs(i);
	}
	int ans=0;
	for(int i=1;i<=idx;++i)
		ans+=siz[i] > 1;
	printf("%d\n",ans);
}
