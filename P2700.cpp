#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
const int N=1e5+7,inf=0x3f3f3f3f;
int n,K;
bool a[N];
vector<pr> G[N];
int f[N],g[N];

void dfs(int u,int fa){
    for(auto i:G[u]){
        int v=i.first,w=i.second;
        if(v==fa)continue;
        dfs(v,u);
        if(a[u]==0){
            f[u]+=min(f[v],g[v]+w);
            g[u]+=min(f[v],g[v]);
        }else{
            g[u]+=min(f[v],g[v]+w);
        }
    }
    if(a[u]==1)f[u]=inf;
}


int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> K;
    for(int i=1,x;i<=K;i++){cin >> x;a[x]=1;}
    for(int i=1,u,v,w;i<n;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    
    cout << min(f[1],g[1]);
}