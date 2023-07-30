#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,M=1e6+7;
int n,m;
vector<int> G[N];
bool vis[N];
int deg[N];
int deg1[N];
int q[N],head=1,top;
int l=1,r;

bool check(int md){
    memcpy(deg1,deg,sizeof deg);
    memset(vis,0,sizeof vis);
    head=1,top=0;
    for(int i=1;i<=n;i++){
        if(deg1[i]<md)q[++top]=i;
    }
    while(head<=top){
        int u=q[head++];
        vis[u]=1;
        for(auto v:G[u]){
            if(vis[v])continue;
            deg1[v]--;
            if(deg1[v]<md)q[++top]=v;
        }
    }
    bool res=0;
    for(int i=1;i<=n;i++){
        if(deg1[i]>=md)res=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1,u,v;i<=m;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++)r=max(r,deg[i]);
    
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
}