#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7,mod=998244353;
int n;
vector<int> G1[N],G2[N];
ll ans;

void dfs(int u,int fa){
    for(auto v:G1[u]){
        if(v==fa)continue;
        G2[u].push_back(v);
        dfs(v,u);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1,u,v;i<=n-1;i++){
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
	dfs(1,0);
    for(int l=1;l<n;l++){
        for(int r=l+1;r<=n;r++){
            for(int u=l;u<=r;u++){
                for(auto v:G2[u]){
                    if(l<=v&&v<=r){
                    	ans++;
                    }
                }
            }
            ans%=mod;
        }
    }
    cout << ans%mod;
}
