#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)>>1)
const int N=1e5+7;
int n,k;
int deg[N];
bool vis[N];
int ud[N];
vector<int> od,G[N];
int res=0;
void dfs(int u,int fa,int d){
    if(!vis[u])vis[u]=1,res++;
    ud[u]=d;
    if(d==0)return;
    for(auto v:G[u]){
        if(vis[v]&&d-ud[v]<2)continue;
        if(v==fa)continue;
        dfs(v,u,d-1);
    }
}

bool check(int xa){
	memset(vis,0,sizeof vis);
    memset(ud,0,sizeof ud);
    res=0;
    for(auto u:od){
        dfs(u,0,xa);
    }
    //printf("%d:%d\n",xa,res);//
    if(res>=n-k)return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=1,u,v;i<=n-1;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++)if(deg[i]==1)od.push_back(i);
    int l=0,r=n;
    while(l<=r){
        if(!check(mid))l=mid+1;
        else r=mid-1;
    }
    while(!check(l))l++;
    while(check(l-1)&&l>=1)l--;
    cout << l+1;
}
