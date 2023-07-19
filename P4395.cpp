#include<bits/stdc++.h>
using namespace std;
#define maxn 20000
vector<int> G[maxn];
int n;
int dp[maxn][22];

void dfs(int u,int fa){
	for(int i=1;i<=15;++i) dp[u][i]=i;
	for(auto v:G[u]){
		if(v==fa) continue;
		dfs(v,u);
		for(int i=1;i<=15;++i){
			int minn=1000000;
			for(int j=1;j<=15;++j){
				if(i==j) continue;
				minn=min(minn,dp[v][j]);
			}
			dp[u][i]+=minn;
		}
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
	
	dfs(1,0);
	
	int ans=1000000;
	for(int i=1;i<=15;++i){
		ans=min(ans,dp[1][i]);
	}
	printf("%d\n",ans);
	return 0;
}
