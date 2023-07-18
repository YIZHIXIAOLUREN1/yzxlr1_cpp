#include<bits/stdc++.h>
using namespace std;
#define maxn 5050
int n,m;

int dfn[maxn],low[maxn];

int to[maxn],nxt[maxn];
int tot,h[maxn];

void add(int u,int v){
	//cout << tot;//
	nxt[++tot]=h[u];to[h[u]=tot]=v;
	nxt[++tot]=h[v];to[h[v]=tot]=u;
}

pair<int,int> ed[maxn];

int cnt,st[maxn],top,bel[maxn],idx,anscnt=0;

void dfs(int u,int las){
	//cout << u << " ";//
	dfn[u]=low[u]=++cnt;
	st[++top]=u;
	for(int i=h[u];i;i=nxt[i]){
		int v=to[i];
		if(v!=las){
			//cout << v;//
			if(!dfn[v]){
				//cout << " no ";//
				dfs(v,u);
				low[u]=min(low[u],low[v]);
				if(low[v]>dfn[u]){
					//cout << u << v;//
					ed[++anscnt]=make_pair(min(u,v),max(u,v));
					//cout << ed[anscnt].first << " " << ed[anscnt].second << endl;//
				}
			}
			else{
				low[u]=min(low[u],low[v]);
				//cout << "y ";//
			}
		}
	}
	//cout << dfn[u] << ":" << low[u] << endl;//
	if(low[u]==dfn[u]){
		int v;
		++idx;
		do{
			v=st[top--];
			bel[v]=idx;
		}while(v!=u);
	}
}

bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first!=b.first)
		return a.first<b.first;
	else return a.second<b.second;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i])dfs(i,-1);
	}
	sort(ed+1,ed+anscnt+1,cmp);
	for(int i=1;i<=anscnt;++i){
		//cout << ed[i].first << " " << ed[i].second << endl;
		printf("%d %d\n",ed[i].first,ed[i].second);
	}
	return 0;
}
