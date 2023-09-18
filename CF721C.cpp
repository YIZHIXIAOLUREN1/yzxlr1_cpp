#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pr pair<int,int>
const int N=5005,max=0x3f3f3f3f;
int n,m,T,rn;
vector<pr> G[N];
int f[N][N];
int g[N][N];
int deg[N];
bool vis[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> T;
    for(int i=1,u,v,t;i<=m;i++){
        cin >> u >> v >> t;
        G[u].push_back({v,t});
        deg[v]++;
    }

    memset(f,0x3f,sizeof f);
    f[1][1]=0;
    rn=n;
    while(rn){
        for(int u=1;u<=n;u++){
            if(!vis[u]&&deg[u]==0){
                for(auto ii:G[u]){
                    int v=ii.first,t=ii.second;
                    for(int i=2;i<=n;i++){
                        f[v][i]=min(f[v][i],f[u][i-1]+t);
                    }
                    deg[v]--;
                }
                rn--;
                break;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(f[n][i]<=T)ans=i;
    }
    cout << ans;
    return 0;
}
