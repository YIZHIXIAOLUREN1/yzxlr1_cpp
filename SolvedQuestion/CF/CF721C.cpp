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
int ans[N];

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
                        if(f[v][i]>f[u][i-1]+t){
                            f[v][i]=f[u][i-1]+t;
                            g[v][i]=u;
                        }
                    }
                    deg[v]--;
                }
                rn--;
                vis[u]=1;
                break;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(f[n][i]<=T)res=i;
    }
    cout << res<<"\n";
    int u=n;
    for(int i=res;i>=1;i--){
        ans[i]=u;
        u=g[u][i];
    }
    for(int i=1;i<=res;i++)cout<<ans[i]<<" \n"[i==n];
    return 0;
}
