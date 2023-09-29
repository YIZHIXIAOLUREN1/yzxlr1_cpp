#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7,mod=998244353;
int n;
vector<int> G[N];
int f[N],g[N],siz[N],ans;

int qq(int x){
    if(x<=1)return 1;
    return 1ll*x*qq(x-1)%mod;
}

void dfs(int u,int fa){
    f[u]=1;
    siz[u]=1;
    g[u]=1;
    for(auto v:G[u]){
        if(v==fa)continue;
        dfs(v,u);
        siz[u]+=siz[v];
        
        f[u]=1ll*f[u]*f[v]%mod;
    }
    f[u]=1ll*f[u]*qq(G[u].size()-1+(fa==0))%mod;
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1,u,v;i<=n-1;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
    	memset(f,0,sizeof f);
    	dfs(i,0);
        printf("%d:%d\n",i,f[i]);//
    	ans=(ans+f[i])%mod;
    }
    cout << ans;
}