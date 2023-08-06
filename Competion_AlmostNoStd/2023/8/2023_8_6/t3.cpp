#include<bits/stdc++.h>
using namespace std;
//#define ll long long
#define pr pair<int,int>
#define prr pair<int,pr>
const int N=1e5+7,K=33;
int n,m,k;
int g[K][K];
int f[N][K][K],ll[N],rr[N];
vector<prr> G[N];
vector<int> av;

void dfs(int u,int fa){
	//cout << "A";//
    if(G[u].size()==1)av.push_back(u);
    for(auto ii:G[u]){
        int v=ii.first,l=ii.second.first,r=ii.second.second;
        if(v==fa)continue;
        ll[v]=l,rr[v]=r;
        for(int i=1;i<=k;i++){
            for(int j=i;j<=k;j++){
                f[v][i][j]=f[u][i][j]+max(0,l-i)+max(0,j-r);
            }
        }
        dfs(v,u);
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;

    for(int i=1,u,v,l,r;i<=m;i++){
        cin >> u >> v >> l >> r;
        G[u].push_back({v,{l,r}});
        G[v].push_back({u,{l,r}});
    }
    dfs(1,0);
    //cout << "A";//
    memset(g,0x3f,sizeof g);
    for(auto u:av){
        for(int i=1;i<=k;i++){
            for(int j=i;j<=k;j++){
                g[i][j]=min(g[i][j],f[u][i][j]);
        		//printf("%d %d:%d\n",i,j,g[i][j]);//
            }
        }
    }

    for(int len=1;len<=k;len++){
        for(int l=1;l<=k-len+1;l++){
            int r=l+len-1;
            for(int i=l;i<r;i++){
            	g[l][r]=min(g[l][r],g[l][i]+g[i+1][r]);
            }
        }
    }
    cout << g[1][k];
}
