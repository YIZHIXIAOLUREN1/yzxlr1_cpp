#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,ans;
int p[N];
bool vis[N];

void dfs(int u){
    vis[u]=1;
    ans--;
    if(!vis[p[u]])dfs(p[u]);
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
        cout << ans << " \n"[i==n];
    }
}