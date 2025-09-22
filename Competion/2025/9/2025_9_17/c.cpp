#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,p[N],mi,ma;
vector<pair<int,int>> G[N];//1 u>v 0 u<v

void dfs(int u,int fa){
    for(auto v:G[u]){
        if(v.first==fa)continue;
        if(v.second){
            p[v.first]=mi-1;
            mi--;
            dfs(v.first,u);
        }else{
            p[v.first]=ma+1;
            ma++;
            dfs(v.first,u);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<n;i++){
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            if(x>y){
                G[u].push_back({v,1});
                G[v].push_back({u,0});
            }else{
                G[u].push_back({v,0});
                G[v].push_back({u,1});
            }
        }
        p[1]=1;
        mi=ma=1;
        dfs(1,0);
        for(int i=1;i<=n;i++)cout<<p[i]-mi+1<<" \n"[i==n];
    }
}
