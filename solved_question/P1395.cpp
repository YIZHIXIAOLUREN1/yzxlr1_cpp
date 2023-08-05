#include<bits/stdc++.h>
using namespace std;
#define maxn 50050
const int inf=0x7f7f7f7f;
int n;
vector<int> G[maxn];
int size[maxn],f[maxn],ans=0;
int cen;

void gc(int u,int fa){
	size[u]=1;f[u]=0;
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if(v==fa) continue;
		gc(v,u);
		size[u]+=size[v];
		f[u]=max(f[u],size[v]);
	}
	f[u]=max(f[u],n-size[u]);
	if(f[u]<f[cen]||(f[u]==f[cen]&&u<cen))
		cen=u;
}
int d[maxn];

void dfs(int u,int fa){
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if(v==fa) continue;
		d[v]=d[u]+1;
		//cout << v << d[v] << endl;//
		ans+=d[v];
		dfs(v,u);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	f[0]=inf;
	gc(1,0);
	d[cen]=0;
	dfs(cen,0);
	printf("%d %d",cen,ans);
}
