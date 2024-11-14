#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,a[N],fa[N];
ll f[N][2],g[N][2];
vector<int> G[N];
int root,vis[N];
ll ans;

void dfs2(int u){
    vis[u]=1;
    f[u][1]=a[u];
    f[u][0]=0;
    g[u][1]=a[u];
    g[u][0]=0;
    for(auto v:G[u]){
        if(v==root)continue;
        dfs2(v);
        f[u][1]+=f[v][0];
        f[u][0]+=max(f[v][0],f[v][1]);
        g[u][1]+=g[v][0];
        g[u][0]+=max(g[v][0],g[v][1]);
    }
    if(u==fa[root])f[u][1]=0;
}

void dfs1(int u){
    vis[u]=1;
    if(!vis[fa[u]])dfs1(fa[u]);
    else{
        root=u;
        dfs2(root);
        ans+=max(max(f[u][0],f[u][1]),g[u][0]);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1,v;i<=n;i++){
        cin >> a[i] >> v;
        G[v].push_back(i);
        fa[i]=v;
    }

    for(int i=1;i<=n;i++)if(!vis[i])dfs1(i);
    cout<<ans;
    return 0;
}
