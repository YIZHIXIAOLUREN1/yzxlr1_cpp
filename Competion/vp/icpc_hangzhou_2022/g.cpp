#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m;
vector<int> G[N];
int gio[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            G[i].clear();
            gio[i]=0;
        }
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
            gio[u]++;gio[v]++;
        }
        if(m>n){
            cout<<"NO\n";
            continue;
        }
        bool fl=1;
        if(m==n-1){
            cout<<"YES\n";
            continue;
        }
        for(int i=1;i<=n;i++)if(gio[i]!=2){fl=0;break;}
        if(!fl){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
}
