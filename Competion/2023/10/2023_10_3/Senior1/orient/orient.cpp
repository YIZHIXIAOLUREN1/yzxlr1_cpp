#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n;
int siz[N];
ll f[N],g[N];
ll ans;
vector<int> G[N];

void dfs1(int u,int fa){
    siz[u]=1;
    for(auto v:G[u]){
        if(v==fa)continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        f[u]+=f[v]+siz[v];
    }
}

void dfs2(int u,int fa){
	ans+=g[u];
    for(auto v:G[u]){
        if(v==fa)continue;
        g[v]=g[u]+n-2*siz[v];
        dfs2(v,u);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("orient.in","r",stdin);
    //freopen("orient.out","w",stdout);
    cin >> n;
    for(int i=1,u,v;i<=n-1;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0);
    g[1]=f[1]-siz[1]+1;
    dfs2(1,0);
    //for(int i=1;i<=n;i++)printf("%d:%d %lld:%lld\n",i,siz[i],f[i],g[i]);//
    cout << 1ll*n*n*n-ans;
}

/*
x->y->z
x!=z
h=lca(x,z)

*/