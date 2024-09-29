#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+7,M=1e4+7;
int n,m,K;
int fa[N];
pair<int,pair<int,int>> G[M];

bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    return a.first<b.first;
}

int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> K;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1,u,v,w;i<=m;i++){
        cin >> u >> v >> w;
        G[i]=make_pair(w,make_pair(u,v));
    }
    sort(G+1,G+m+1,cmp);

    int cnt=0,ans=0;
    for(int i=1;i<=m;i++){
        int u=G[i].second.first,v=G[i].second.second;
        if(find(u)==find(v))continue;
        fa[fa[v]]=u;
        cnt++;ans+=G[i].first;
        if(cnt==n-K){cout<<ans;return 0;}
    }
    cout<<"No Answer";

    return 0;
}
