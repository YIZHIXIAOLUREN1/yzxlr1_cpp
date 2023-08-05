#include<bits/stdc++.h>
using namespace std;
#define M 300050
#define N 200050
#define pr pair<int,int>
int n,m,k,mx;
vector<pr> G[N];
int a[N];
bool vis[N],tr;

void dfs1(int u,int fas){
	if(tr)return;
    vis[u]=1;
    for(auto v:G[u]){
        if(vis[v.first]){
        	if((a[u]^a[v.first])!=v.second){tr=1;return;}
        	continue;
        }
        a[v.first]=v.second^a[u];
        dfs1(v.first,u);
    }
}
void dfs2(int u);
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int Tt;cin >> Tt;
while(Tt--){
	tr=0;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        G[i].clear();vis[i]=0,a[i]=0;
    }
    for(int i=1,u,v,y;i<=m;i++){
        cin >> u >> v >> y;
        G[u].push_back({v,y});
        G[v].push_back({u,y});
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs1(mx=i,1);
    if(tr){cout << "-1" << endl;continue;}
    memset(vis,0,sizeof vis);
    
    a[mx]=k-1;
    dfs2(mx);
    
    for (int i = 1; i <= n; i++)
		cout << a[i] << "\n "[i + 1 <= n];
}}
void dfs2(int u){
    vis[u]=1;
    for(auto v:G[u]){
        if(vis[v.first])continue;
        a[v.first]=v.second^a[u];
        dfs1(v.first,u);
    }
}