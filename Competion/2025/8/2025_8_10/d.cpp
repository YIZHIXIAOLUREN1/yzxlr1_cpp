#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e5+7;
int n,d[N];
vector<int> G[N];
int maxd,root1,ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        root1=1;
        ans=0;
        for(int i=1;i<=n;i++){
            G[i].clear();
        }
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(G[i].size()==1)ans++;
        }
        int res1=0,res2=0;
        for(int u=1;u<=n;u++){
            res2=0;
            for(auto v:G[u]){
                if(G[v].size()==1)res2++;
            }
            if(G[u].size()==1)res2++;
            res1=max(res1,res2);
        }
        cout<<ans-res1<<"\n";
    }
}