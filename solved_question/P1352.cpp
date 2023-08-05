#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 6050
int n;
int r[maxn],fa[maxn];
vector<int> G[maxn];
ll dp[maxn][3];

void dfs(int u,int faa){
	//printf("%d:\n  ",u);
	ll gg[2];
	gg[0]=gg[1]=0;
	bool flag=1;
	for(auto v:G[u]){
		if(v==faa) continue;
		flag=0;
		//printf("son%d:\n  ",v);
		dfs(v,u);
		gg[0]+=max(dp[v][0],dp[v][1]);
		gg[1]+=dp[v][0];
	}
	
	if(flag){
		dp[u][0]=0;
		dp[u][1]=r[u];
		return;
	}
	
	dp[u][0]=gg[0];
	dp[u][1]=gg[1]+r[u];
	//printf("%d %d\n",dp[u][0],dp[u][1]);
}

int main(){
	scanf("%d",&n);
	int fir=1;
	for(int i=1;i<=n;++i)
		scanf("%d",&r[i]);
	for(int i=1;i<=n-1;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		fa[u]=v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	while(fa[fir]!=0) fir=fa[fir];
	
	dfs(fir,0);
	
	printf("%lld\n",max(dp[fir][0],dp[fir][1]));
}
