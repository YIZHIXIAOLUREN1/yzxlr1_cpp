#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7,mod=998244353;
int n,m;
vector<int> G[N];
vector<int> qf[N];
int qfcnt;
int iqf[N];
int inq[N];
vector<int> Gqf[N];
int dfn[N],cnt,low[N],vis[N];
int niq[N],nicnt;

void dfs(int u){
    low[u]=dfn[u]=++cnt;
    vis[u]=1;
    niq[++nicnt]=u;
    for(auto v:G[u]){
        if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }else if(!dfn[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
    }

    if(low[u]==dfn[u]){
        qfcnt++;
        int vv=niq[nicnt];
        do{
        	vv=niq[nicnt--];
            iqf[vv]=qfcnt;
            vis[vv]=0;
            qf[qfcnt].push_back(vv);
            
        }while(vv!=u);
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }

    for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);

    for(int u=1;u<=n;u++){
        for(auto v:G[u]){
            if(iqf[u]==iqf[v])continue;
            inq[iqf[v]]++;
        }
    }
    int ans=0;
    for(int i=1;i<=qfcnt;i++)if(!inq[i])ans++;
    cout<<ans;
    return 0;
}
