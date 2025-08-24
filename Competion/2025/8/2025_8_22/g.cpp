#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107,maxn=2e9+7;
int n,Q;
int Y[N][N],T[N][N];
int res;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>Q;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    cin>>Y[i][j];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    cin>>T[i][j];
    while(Q--){
        int u,v;
        cin>>u>>v;
        res=maxn;
        if(Y[u][v]>=0)res=Y[u][v];
        for(int k=1;k<=n;k++){
            if(k==u||k==v)continue;
            if(T[u][k]>=0&&T[k][v]>=0)res=min(res,T[u][k]+T[k][v]);
        }
        if(res==maxn)cout<<"-1\n";
        else cout<<res<<"\n";
    }
}
