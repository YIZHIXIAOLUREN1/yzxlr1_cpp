#include<bits/stdc++.h>
using namespace std;
#define N 100050
#define M 1000050
#define ll long long
int n,m;
int head[N],nxt[M],to[M],tot=1;
int low[N],dfn[N],st[N],top,cnt;
int deg[N],size[N],idx;
ll ans[N];
void addd(int u,int v){
    nxt[++tot]=head[u];
    to[head[u]=tot]=v;
}
#define add(x,y) addd(x,y);addd(y,x)

void dfs(int u){
    low[u]=dfn[u]=++cnt;
    st[++top]=u;
    size[u]=1;
    ll mz=0;
    for(int i=head[u];i;i=nxt[i]){
        int v=to[i];
        if(dfn[v]){
            low[u]=min(low[u],dfn[v]);
            continue;
        }
        dfs(v);
        size[u]+=size[v];
        low[u]=min(low[u],low[v]);
        if(low[v]>=dfn[u]){
            deg[u]++;
            ans[u]+=size[v]*mz;
            mz+=size[v];
            int vv;
            do{
                vv=st[top--];
                deg[vv]++;
            }while(vv!=v);
        }
    }
    ans[u]+=mz*(n-mz-1);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1,u,v;i<=m;i++){
        cin >> u >> v;
        add(u,v);
    }
    dfs(1);
    
    for(int i=1;i<=n;i++){
    	cout << ans[i]*2+2*n-2<<"\n";
    }
}