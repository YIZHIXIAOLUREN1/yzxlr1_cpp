#include<bits/stdc++.h>
using namespace std;
#define maxn 500050
int n,s;
vector<int> G[maxn];
int anc[maxn][21];
int d[maxn];

void dfs(int u,int fa){
	for(int v:G[u]){
		if(v==fa) continue;
		d[v]=d[u]+1;
		anc[v][0]=u;
		dfs(v,u);
	}
}

void init(){
	for(int j=1;j<=20;++j)
		for(int i=1;i<=n;++i)
			anc[i][j]=anc[anc[i][j-1]][j-1];
}

int lca(int u,int v){
	if(d[u]<d[v]) swap(u,v);
	for(int i=20;i>=0;--i)
		if(d[anc[u][i]]>=d[v])
			u=anc[u][i];
	if(u==v) return u;
	else for(int i=20;i>=0;--i)
		if(anc[u][i]!=anc[v][i])
			u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}

int main(){
	int m;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	d[s]=1;
	dfs(s,0);
	init();
	
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
}
