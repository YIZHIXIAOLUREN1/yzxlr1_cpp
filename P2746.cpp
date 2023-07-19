#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int n;
int to[20000],h[maxn],nxt[maxn],tot,from[maxn];
void add(int u,int v){
	nxt[++tot]=h[u];
	to[tot]=v;
	h[u]=tot;
	from[tot]=u;
}

int dfn[maxn],low[maxn],bel[maxn],st[maxn],cnt,top,idx;
bool ins[maxn];
int in[maxn],out[maxn],in0,out0;
void dfs(int u){
	dfn[u]=low[u]=++cnt;
	ins[st[++top]=u]=1;
	for(int i=h[u];i;i=nxt[i]){
		if(!dfn[to[i]]){
			dfs(to[i]);
			low[u]=min(low[u],low[to[i]]);
		} else if(ins[to[i]]){
			low[u]=min(low[u],dfn[to[i]]);
		}
	}
	if(low[u]==dfn[u]){
		int v;++idx;
		do{
			v=st[top--];
			ins[v]=0;
			bel[v]=idx;
		}while(v!=u);
	}
	return;
}

void rw(){
	for(int i=1;i<=tot;++i){
		int u=from[i],v=to[i];
		if(bel[u]!=bel[v]){
			out[bel[u]]++;
			in[bel[v]]++;
		}
	}
	for(int i=1;i<=idx;++i){
		if(in[i]==0) in0++;
		if(out[i]==0) out0++;
	}
	if(idx==1) cout << "1\n0\n";
	else cout << in0 << "\n" << max(in0,out0) << "\n";
	return;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			int a;
			scanf("%d",&a);
			if(a==0) break;
			add(i,a);
		}
	for(int i=1;i<=n;++i)
	if(!dfn[i]) dfs(i);
	
	rw();
	return 0;
}
