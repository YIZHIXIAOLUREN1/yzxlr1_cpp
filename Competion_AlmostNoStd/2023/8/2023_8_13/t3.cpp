#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
int n,K;
int d[N];
vector<int> G[N];
vector<int> P[N];
vector<int> ans[N][N];
bool vis[N][N][N];

void dfs(int u,int fa){
    d[u]=d[fa]+1;
    for(auto v:G[u]){
        if(v==fa)continue;
        dfs(v,u);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> K;
    for(int k=1;k<=K;k++){
        for(int i=1,u,v;i<=n-1;i++){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,0);
    }
}
