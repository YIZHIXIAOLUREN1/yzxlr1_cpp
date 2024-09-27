#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7,mod=100003,inf=0x3f3f3f3f;
int n,m;
vector<int> G[N];
int dis[N],ans[N];
int vis[N];
priority_queue<pair<int,int>> q;

void dij(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0,ans[1]=1;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto v:G[u]){
        	//printf("%d:%d:%d %d\n",u,v,dis[u],dis[v]);//
            if(dis[v]<dis[u]+1)continue;
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                ans[v]=1;
            }else{
                ans[v]=(ans[v]+1)%mod;
            }
            q.push(make_pair(dis[v],v));
            vis[v]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1,u,v;i<=m;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dij();
    for(int i=1;i<=n;i++){
        if(ans[i]==inf)cout<<"-1\n";
        else cout<<ans[i]%mod<<"\n";
    }
    return 0;
}
