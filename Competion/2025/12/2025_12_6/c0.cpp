#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+7,mod=998244353;
int n,m,c[N][N];
bool vis[N][N];
int ne=0;
ll ans=1;
void Solve(){
    cin>>n>>m;
    ne=0;
    ans=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)vis[i][j]=0;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)c[i][j]=s[j-1]=='#';

        if(i==1){
            for(int j=1;j<=m;j++)if(c[i][j])ne++;
            continue;
        }
        int rne=0;
        for(int j=1;j<=m;j++){
            if(!c[i][j])continue;
            if(j>1&&c[i-1][j-1]&&!vis[i-1][j-1]){
                vis[i-1][j-1]=1;
                continue;
            }
            if(j<m&&c[i-1][j+1]&&!vis[i-1][j+1]){
                vis[i-1][j+1]=1;
                continue;
            }
            rne++;
        }

        

        ne+=rne;
    }

    cout<<ne<<" "<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
/*



*/