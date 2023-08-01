#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+7;
int n;
vector<int> G[N];
int q[N];
int size[N],dp[N],son[N],top[N],fa[N];
int ans[N];
void dfs1(int u,int f){
    fa[u]=f;
    size[u]=1;
    dp[u]=dp[f]+1;
    for(auto v:G[u]){
        if(v==f)continue;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]])son[u]=v;
    }
}

void dfs2(int u,int tp){
    top[u]=tp;
    if(son[u])dfs2(son[u],tp);
    for(auto v:G[u]){
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

int LCA(int x,int y){
    if(dp[x]<dp[y])swap(x,y);
    while(top[x]!=y){
        x=top[x];
        if(dp[x]<dp[y])swap(x,y);
    }
    return x;
}

void dfs3(int u){
    for(auto v:G[u]){
        if(v==fa[u])continue;
        ans[u]+=ans[v];
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> q[i];
    for(int i=1,u,v;i<n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    for(int i=1;i<n;i++){
        int x=q[i],y=q[i+1];
        int lca=LCA(x,y);
        ans[x]++,ans[y]++,ans[lca]++,ans[fa[lca]]++;
    }
    dfs3(1);
    ans[q[n]]--;
    for(int i=1;i<=n;i++)cout << ans[i] <<"\n";
}
