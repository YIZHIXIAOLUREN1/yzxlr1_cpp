#include<bits/stdc++.h>
using namespace std;
#define maxn 20000
#define ll long long
int n;
ll v[maxn];
vector<int> G[maxn];
ll dp[maxn],ans=-3000000000;
bool vis[maxn];

ll dfs(int u,int fa){
	if(vis[u]) return dp[u];
	else{
		dp[u]=v[u];
		for(auto v:G[u]){
			if(v==fa) continue;
			dfs(v,u);
			if(dp[v]>0) dp[u]+=dp[v];
		}
		if(dp[u]>ans) ans=dp[u];
		return dp[u];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&v[i]);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1,0);
	printf("%lld\n",ans);
	
}
