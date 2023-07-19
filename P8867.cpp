#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 1001000
const int mod=1000000007;
int n,m;
struct node{
	int from;
	int to;
	int nxt;
} edge[maxn*2];
int h[maxn],tot=1;

void read(){};
template<class T1,class ...T2>
inline void read(T1& ret,T2&... rest){
    ret=0;char c=getchar();bool f=false;
    while(c<'0'||c>'9'){f=c=='-';c=getchar();}
    while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
    if(f)ret=-ret;
    read(rest...);
}
#define cin(...) read(__VA_ARGS__)

void add(int u,int v){
	edge[++tot].to=v;
	edge[tot].from=u;
	edge[tot].nxt=h[u];
	h[u]=tot;
}

int dfn[maxn],low[maxn],st[maxn],cnt,top,bel[maxn],ins;
int a[maxn];
void dfs(int u,int las){
	dfn[u]=low[u]=++cnt;
	st[++top]=u;
	//printf("u%d %d:\n",u,cnt);
	for(int i=h[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		//printf("i:%d %d\n",i,las^1); 
		if(i==(las^1)) continue;
		//printf("son%d:",v);
		if(!dfn[v]){
			dfs(v,i);
			//printf("zgx%d %d\n",low[u],low[v]);
			low[u]=min(low[u],low[v]);
		}else{
			//printf("gx%d %d\n",low[u],dfn[v]);
			low[u]=min(low[u],dfn[v]);
		}
	}
	
	if(dfn[u]==low[u]){
		ins++;
		int v;
		do{
			v=st[top--];
			bel[v]=ins;
		}while(u!=v);
		//printf("d%d %d\n",ins,bi[ins]);
	}
}

vector<int> G[maxn];
int dp[maxn];
int sz[maxn];

int sq[maxn*2];
int cntt;
int ans;
bool vis[maxn];


void dfs1(int u,int fa){
	vis[u]=1;
	sz[u]=1;
	//cout << "a";//
	//printf("a%d %d:\n",u,fa);
	dp[u]=sq[a[u]];
	for(auto v:G[u]){
		if(v==fa||vis[v]) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		dp[u]=dp[u]*((sq[sz[v]]+dp[v])%mod)%mod;
		//printf("%d,%d:%d %d %d\n",u,v,gg[0],gg[1],gg[2]);
	}
	
	dp[u]=((dp[u]-sq[sz[u]-1])%mod+mod)%mod;
	int s=dp[u];
	for(auto v:G[u]){
		if(v==fa) continue;
		s-=dp[v]*sq[sz[u]-sz[v]-1]%mod;
	}
	ans+=(s%mod+mod)*sq[ins-sz[u]]%mod;
	//printf(":%d %d %d %d\n",dp[u][0],dp[u][1],dp[u][2],dp[u][3]);
}

signed main(){
	//freopen("barrack2.in","r",stdin);
	//for(int i=0;i<=10;++i)printf("%d %d:\n",i,bpow(i,i));
	//cout << bpow(2,10);//
	cin(n,m);
	sq[0]=1;
	for(int i=1;i<=m+n;++i) sq[i]=(sq[i-1]*2)%mod;
	for(int i=1;i<=m;++i){
		int u,v;
		cin(u,v);
		add(u,v);
		add(v,u);
	}
	
	for(int i=1;i<=n;++i)
		if(!dfn[i]) dfs(i,-1);
	//cout << "A";//
	for(int i=1;i<=n;++i){
		a[bel[i]]++;
		for(int j=h[i];j;j=edge[j].nxt){
			int v=edge[j].to;
			//cout << v << endl;
			if(bel[i]!=bel[v])
				G[bel[i]].push_back(bel[v]);
			else cntt++;
		}
	}
	/*
	for(int i=1;i<=ins;++i){
		printf("b%d %d",i,a[i]);//
	}
	*/
	//memset(vis,0,sizeof(vis));
	dfs1(1,0);
	ans=ans%mod*sq[cntt/2]%mod;
	cout << ans << endl;
}
