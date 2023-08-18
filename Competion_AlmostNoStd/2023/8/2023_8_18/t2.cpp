#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5007,mod=998244353;
int n,h,w;
int f[2][N],g[2][N];
int sf[2][N],sg[2][N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> h >> w;
    for(int j=1;j<h;j++)f[1][j]=1;
    g[1][h]=1;
    for(int j=1;j<=min(n,h);j++){
    	sf[1][j]=sf[1][j-1]+f[1][j];
    	sg[1][j]=sg[1][j-1]+g[1][j];
    }
    for(int i=2;i<=w;i++){
        int ni=i&1,li=(i&1)^1;
        for(int j=i;j<=min(i*h,n);j++){
            f[ni][j]=sf[li][min(j-1,(i-1)*h)]-sf[li][max(j-h+1,i-1)-1];
            g[ni][j]=sg[li][min(j-1,(i-1)*h)]-sg[li][max(j-h+1,i-1)-1];
            if(j-h>=i-1)g[ni][j]=(g[ni][j]+f[li][j-h]+g[li][j-h])%mod;
            sf[ni][j]=(sf[ni][j-1]+f[ni][j])%mod;
            sg[ni][j]=(sg[ni][j-1]+g[ni][j])%mod;
        }
    }
    cout << g[w&1][n];
}
