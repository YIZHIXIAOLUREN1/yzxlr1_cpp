#include<bits/stdc++.h>
using namespace std;
#define N 50050
int n,K;
vector<int> G[N];
int fa[N],d[N],V[N];
int pre[N][20];

void dfs1(int u,int fs){
    fa[u]=fs;
    d[u]=d[fs]+1;
    //printf("%d:%d %d\n",u,fa[u],d[u]);//
    for(auto v:G[u]){
        if(v==fs)continue;
        dfs1(v,u);
    }
}

void pr(){
    for(int i=1;i<=n;i++)pre[i][1]=fa[i];
    for(int j=2;j<=17;j++){
        for(int i=1;i<=n;i++){
            pre[i][j]=pre[pre[i][j-1]][j-1];
            //printf("%d %d:%d\n",i,j,pre[i][j]);//
        }
    }
}

int lca(int u,int v){
	//printf("%d %d:",u,v);//
    if(d[u]<d[v])swap(u,v);
    for(int j=17;j>=1;j--){
    	//printf("%d;%d ",j,pre[u][j]);//
        if(d[pre[u][j]]>d[v])u=pre[u][j];
    }
    if(d[u]!=d[v])u=fa[u];
    //printf("%d ",u);//
    for(int j=17;j>=1;j--){
        if(pre[u][j]!=pre[v][j]){
            u=pre[u][j],v=pre[v][j];
        }
    }
    if(u!=v)u=fa[u];
    //printf("%d\n",u);//
    return u;
}
int ans;
void dfs2(int u,int w){
    ans=max(ans,w);
    for(auto v:G[u]){
        if(v==fa[u])continue;
        dfs2(v,w);
        V[u]+=V[v];
    }
	ans=max(ans,V[u]);
}

int main(){
    scanf("%d%d",&n,&K);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0);
    pr();
    for(int i=1;i<=K;i++){
        int s,t;
        scanf("%d%d",&s,&t);
        int lc=lca(s,t);
        V[lc]--;V[fa[lc]]--;
        V[s]++;V[t]++;
        //printf("%d %d:%d\n",s,t,lc);//
    }
    dfs2(1,0);
    printf("%d",ans);
}