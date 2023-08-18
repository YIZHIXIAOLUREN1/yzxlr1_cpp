#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5007,mod=998244353;
int n,h,w;
int f[N][N],g[N][N];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> h >> w;
    for(int j=1;j<h;j++)f[1][j]=1;
    g[1][h]=1;
    for(int i=2;i<=w;i++){
        for(int j=i;j<=min(i*h,n);j++){
            for(int k=max(j-h+1,i-1);k<=j-1;k++){
                f[i][j]=(f[i][j]+f[i-1][k])%mod;
                g[i][j]=(g[i][j]+g[i-1][k])%mod;
            }
            if(j-h>=i-1)g[i][j]=(g[i][j]+f[i-1][j-h]+g[i-1][j-h])%mod;
        }
    }
    cout << g[w][n];
}