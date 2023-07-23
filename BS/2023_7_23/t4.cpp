#include<bits/stdc++.h>
using namespace std;
const int N=4e3+7,mod=998244353;
#define ll long long 
int n,m,K;
bool vis[N];
ll f[N][N];

int main(){
    cin >> n >> m >> K;
    for(int i=m;i<=n;i+=m)vis[i]=1;

    for(int i=0;i<=n;i++){
        if(vis[i])continue;
        f[1][i]=1;
    }

    for(int i=2;i<=K;i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<=j-i+1;k++){
                if(vis[k])continue;
                f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
            }
            //printf("%d %d:%lld\n",i,j,f[i][j]);//
        }
    }
    cout << f[K][n];
}