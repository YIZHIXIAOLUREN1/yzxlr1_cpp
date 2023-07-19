#include<bits/stdc++.h>
using namespace std;
#define maxn 500050
int n,m;
vector<int> G[maxn];
int anc[maxn][21];
int d[maxn];

void dfs(int u,int fa){
	//printf("%d %d %d\n",u,d[u],fa);
	for(auto v:G[u]){
		if(v==fa) continue;
		d[v]=d[u]+1;
		anc[v][0]=u;
		dfs(v,u);
	}
}

void init(){
	for(int j=1;j<=20;++j)
		for(int i=1;i<=n;++i){
			anc[i][j]=anc[anc[i][j-1]][j-1];
			//printf("%d %d %d\n",i,j,anc[i][j]);
		}
}

int lca(int u,int v){
	//printf("%d %d",u,v);//
	if(d[u]<d[v]) swap(u,v);
	for(int j=20;j>=0;--j)
		if(d[anc[u][j]]>=d[v])
			u=anc[u][j];
	if(u==v) return u;
	for(int j=20;j>=0;--j)
		if(anc[u][j]!=anc[v][j])
			u=anc[u][j],v=anc[v][j];
	//cout << anc[u][0] << " " << u << endl;//
	return anc[u][0];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	d[1]=1;
	dfs(1,0);
	init();
	
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		int u=lca(x,y),v=lca(x,z),w=lca(y,z),k;
		if(u==v) k=w;
		else if(u==w) k=v;
		else if(v==w) k=u;
		int ans=d[x]+d[y]+d[z]-d[u]-d[v]-d[w];
		//printf("%d %d %d ",u,v,w);
		printf("%d %d\n",k,ans);
	}
}
