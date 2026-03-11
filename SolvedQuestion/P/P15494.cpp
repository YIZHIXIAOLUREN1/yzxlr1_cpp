#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,m,cro;
vector<int> G[N];
int d[N];

void dfs(int u,int fa){
    d[u]=d[fa]+1;
    for(auto v:G[u]){
    	if(v==fa||d[v]>d[u])continue;
        if(!d[v])dfs(v,u);
        else if((d[v]-d[u])%2==0)cro++;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++)if(!d[i])dfs(i,0);
    cout<<m-cro+1<<"\n";
}