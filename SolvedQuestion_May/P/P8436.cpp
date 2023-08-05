#include<bits/stdc++.h>
using namespace std;
#define maxn 600000
int n,m;

vector<int> G[maxn];
int dfn[maxn],low[maxn],tot=0;
int st[maxn],top=0,ins,sum[maxn];
vector<int> bel[maxn];

void dfs(int u,int fa){
	dfn[u]=low[u]=++tot;
	st[++top]=u;
	//printf("%d %d:\n",u,tot);//
	int flag=1;
	for(auto v:G[u]){
		if(v==fa&&flag){
			flag=0;
			continue;
		}
		//cout << v << " ";//
		if(!dfn[v]){
			dfs(v,u);
			//printf("1%d %d\n",low[u],low[v]);//
			low[u]=min(low[u],low[v]);
			
		}else{
			//printf("2%d %d\n",low[u],dfn[v]);//
			low[u]=min(low[u],dfn[v]);
		}
	}
	
	if(low[u]==dfn[u]){
		ins++;
		//printf("%d %d %d %d:\n",u,low[u],dfn[u],ins);
		int v;
		do{
			v=st[top--];
			sum[ins]++;
			bel[ins].push_back(v);
			//printf("%d %d\n",v,sum[ins]);
		}while(u!=v);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i=1;i<=n;++i)
		if(!dfn[i]) dfs(i,0);
	
	printf("%d\n",ins);
	for(int i=1;i<=ins;++i){
		printf("%d",sum[i]);
		for(int j=0;j<bel[i].size();++j){
			printf(" %d",bel[i][j]);
		}
		printf("\n");
	}
	
}
