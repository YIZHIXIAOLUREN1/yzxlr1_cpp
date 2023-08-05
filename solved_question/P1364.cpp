#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
#define ll long long
int n,w[maxn],size[maxn],s[maxn][2],dep[maxn];
ll f[maxn],ans;
void dfs(int u){
	size[u]=w[u];
	for(int i=0;i<2;++i){
		int v=s[u][i];
		if(v==0) continue;
		dep[v]=dep[u]+1;
		dfs(v);
		size[u]+=size[v];
	}
	//printf("d%d %d %d %d\n",u,w[u],dep[u],size[u]);//
	f[1]+=w[u]*dep[u];
}

void dp(int u){
	for(int i=0;i<2;++i){
		int v=s[u][i];
		if(v==0) continue;
		f[v]=f[u]-size[v]*2+size[1];
		//cout << v << " " << f[v] << "\n";//
		ans=min(ans,f[v]);
		dp(v);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&w[i],&s[i][0],&s[i][1]);
	dfs(1);
	//cout << f[1] << endl;//
	ans=f[1];
	dp(1);
	printf("%lld\n",ans);
}
