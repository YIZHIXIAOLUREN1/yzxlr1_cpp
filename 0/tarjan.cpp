#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m;
vector<int> G[N];
int dfn[N],low[N],tot,vis[N];
int st[N],top,icp[N],tcp;
vector<int> cp[N];
int ci[N];

void dfs(int u){
    low[u]=dfn[u]=++tot;
    st[++top]=u;
    vis[u]=1;
    for(auto v:G[u]){
        if(vis[v])low[u]=min(low[u],dfn[v]);
        else if(!dfn[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==dfn[u]){
        tcp++;
        //printf("cc%d:%d\n",u,tcp);//
        int vv;
        do{
            vv=st[top--];
            icp[vv]=tcp;
            vis[vv]=0;
            cp[tcp].push_back(vv);
        }while(vv!=u);
    }
    //printf("%d:%d %d\n",u,dfn[u],low[u]);//
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        if(u==v)continue;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);

    for(int u=1;u<=n;u++){
        for(auto v:G[u]){
            if(icp[u]==icp[v])continue;
            ci[icp[v]]++;
        }
    }
    int ans=0;
    for(int i=1;i<=tcp;i++){
    	//printf("c%d:%d %d\n",i,cp[i].size(),ci[i]);//
        if(!ci[i])ans++;
    }
    cout << ans;
    return 0;
}