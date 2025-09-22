#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,sol[N];
vector<int> G[N];
bool vis[N];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        if(u==0&&v==0){
            sol[i]=1;
            q.push(i);
        }else{
            G[u].push_back(i);
            G[v].push_back(i);
        }
    }

    
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto v:G[u]){
            if(!sol[v]){
                sol[v]=1;
                q.push(v);
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        if(sol[i])ans++;
    }
    
    cout<<ans;
}
