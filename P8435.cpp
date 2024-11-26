#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7,mod=998244353;
int n,m;
vector<int> G[N];
int dfn[N],low[N],cnt,st[N],top,vis[N];
bool gd[N];
int ans;
vector<int> gcc[N];
int tot;
void dfs(int u,int fa){
    int sz=0;
    low[st[++top]=u]=dfn[u]=++cnt;
    vis[u]=1;
    if(u==fa&&G[u].size()==0){
        gcc[++tot].push_back(u);
        return;
    }
    int vf=0;
    for(auto v:G[u]){
        if(!dfn[v]){
            sz++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                tot++;
                do{
                    gcc[tot].push_back(st[top--]);
                }while(st[top+1]!=v);
                gcc[tot].push_back(u);
            }
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(u==v)continue;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,i);
    //cout<<ans<<"\n";//
    //for(int i=1;i<=n;i++)if(gd[i])cout<<i<<" ";//
    //cout<<"\n";//
    cout<<tot<<"\n";
    for(int i=1;i<=tot;i++){
    	cout<<gcc[i].size()<<" ";
        for(int j=0;j<gcc[i].size();j++)cout<<gcc[i][j]<<" \n"[j==gcc[i].size()-1];
    }
    cout<<"\n";
    
    return 0;
}
