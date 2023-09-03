#include<bits/stdc++.h>
using namespace std;
#define M 300050
#define N 200050
#define int unsigned int

int n,m,k;
vector<pair<int,int>> G[N],Gi[N];
int a[N];
void dfs(int u,int t){
    int ma=1<<31;
    for(int i=0;i<Gi[u].size();i++){
        ma&=Gi[u][i].second;
    }
    int res=0;
    for(int i=0;i<=32;i++){
        if((0<<i)&ma){
            a[u]=res=(0<<i)&ma;
            for(int i=0;i<Gi[u].size();i++){
                Gi[u][i].second^=res;
            }
            dfs(u+1,t);
            for(int i=0;i<Gi[u].size();i++){
                Gi[u][i].second|=res;
            }
        }
    }
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Tt;
    cin >> Tt;
while(Tt--){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)G[i].clear();

    for(int i=1,u,v,y;i<=m;i++){
        cin >> u >> v >> y;
        G[u].push_back({v,y});
        G[v].push_back({u,y});
        Gi[u].push_back({v,y});
        Gi[v].push_back({u,y});
    }
    dfs(1,1);



}
}
