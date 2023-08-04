#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7,inf=0x3f3f3f3f;
int n,m,ss;
int dis[N];
bool vis[N];
vector<int> G[N];
struct node{
    int id,di;
    friend bool operator < (node a,node b){
        return a.di>b.di;
    }
};
priority_queue<node> q;
int ans;
void dij(){
    vis[ss]=1;
    dis[ss]=1;
    q.push({ss,1});
    while(!q.empty()){
        int u=q.top().id;
        q.pop();
        vis[u]=0;
        for(auto v:G[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                if(!vis[v])q.push({v,dis[v]}),vis[v]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)if(dis[i]!=inf)ans=max(ans,dis[i]);
    for(int i=1;i<=n;i++){
        if(dis[i]==inf)continue;
        for(auto v:G[i]){
            if(dis[v]==inf)continue;
            if(abs(dis[i]-dis[v])>1){
                ans=-1;
                i=n+1;
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dis,0x3f,sizeof dis);
    cin >> n >> m;
    for(int i=1,u,v;i<=m;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> ss;
    dij();
    cout << ans;
}
