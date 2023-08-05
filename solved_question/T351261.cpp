#include<bits/stdc++.h>
using namespace std;
#define N 2000500
int n,m,w[N];
int s[N];
int fa[N];
vector<int> G[N],s0[N];


void dfs1(int u,int fas){
    fa[u]=fas;
    for(auto v:G[u]){
        if(v==fas)continue;
        if(!s[v])s0[u].push_back(v);
        dfs1(v,u);
    }
}
priority_queue<pair<int,int>> q;

void ad(int x){s[x]=1;q.push({w[x],x});}
void de(int x){s[x]=0;}
void ge(){
    while(s[q.top().second]==0)q.pop();
    printf("%d\n",q.top().first);
}

void cg(int u){
    de(u);
    s0[fa[u]].push_back(u);
    for(auto v:s0[u]){
        if(v==fa[u])continue;
        ad(v);
    }
    s0[u].clear();
}
int ans,anw;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){scanf("%d",&s[i]);if(s[i])ad(i);}
    dfs1(1,0);
    ge();
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        if(s[x])cg(x);
        else ad(x);
        ge();
    }
}