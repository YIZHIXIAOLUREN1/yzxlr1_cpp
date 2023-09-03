#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n;
vector<int> G[N];
bool vis[N];

void dfs(int u,int fa,int st){
    vis[u]=1;
    if(st){
        if(u!=1)cout << u << " ";
        else cout << u;
        for(auto v:G[u]){
            if(v==fa||vis[v])continue;
            dfs(v,u,0);
        }
    }else{
        for(auto v:G[u]){
            if(v==fa||vis[v])continue;
            dfs(v,u,1);
        }
        if(u!=1)cout << u << " ";
        else cout << u;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1,u,v;i<n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1,0);
}