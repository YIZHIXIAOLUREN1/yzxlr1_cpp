#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,m,k;
vector<int> G[N];
bool vis[N];
int res;
bool a[N];
int q[N],l,r;
vector<pair<int,pair<int,vector<int> > > > ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int ai;
        cin>>ai;
        a[ai]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(k==n){cout<<"No";return 0;}
    int root=1;
    for(int i=1;i<=n;i++){
        if(!a[i]){root=i;break;}
    }
    l=r=1;
    q[1]=root;
    vis[root]=1;
    res++;
    pair<int,vector<int> > re;
    while(l<=r){
        int u=q[l];l++;
        if(a[u])continue;
        
        re.first=0;re.second.clear();
        for(auto v:G[u]){
            if(vis[v])continue;
            re.first++;
            re.second.push_back(v);
            vis[v]=1;
            res++;
            q[++r]=v;
        }
        if(re.first){ans.push_back({u,re});}
    }
    if(res<n){cout<<"No";return 0;}
    cout<<"Yes\n";
    cout<<ans.size()<<"\n";
    for(auto [u,rre]:ans){
        cout<<u<<" "<<rre.first<<" ";
        for(auto v:rre.second)cout<<v<<" ";
        cout<<"\n";
    }
}
