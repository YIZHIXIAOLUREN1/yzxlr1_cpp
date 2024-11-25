#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+7,mod=998244353;
int n,m;
vector<int> G[N];
int dfn[N],low[N],cnt,st[N],top,vis[N];
bool gd[N];
int ans;
void dfs(int u,int fa){
    int sz=0;
    low[st[++top]=u]=dfn[u]=++cnt;
    vis[u]=1;
    for(auto v:G[u]){
        if(!vis[v]){
            sz++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(fa!=u&&low[v]>=dfn[u]&&!gd[u]){
                gd[u]=1;ans++;
            }
        }else if(v!=fa){
            low[u]=min(low[u],dfn[v]);
        }

        if(fa==u&&sz>=2&&!gd[u]){
            gd[u]=1;ans++;
        }
    }

}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,i);
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)if(gd[i])cout<<i<<" ";
    cout<<"\n";
    
    return 0;
}
