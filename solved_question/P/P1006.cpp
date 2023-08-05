#include<bits/stdc++.h>
using namespace std;
#define N 55
#define ma(a,b,c,d) (max(max(max(a,b),c),d))
int n,m;
int a[N][N];
int f[N][N][N];


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> m >> n;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    cin >> a[i][j];

    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=m;k++){
        int l=i+j-k;
        if(l<1||l>n)continue;
        f[i][j][k]=ma(f[i-1][j][k-1],f[i][j-1][k-1],
        f[i-1][j][k],f[i][j-1][k]);
        f[i][j][k]+=a[i][j]+a[k][l];
        if(i==k&&j==l)f[i][j][k]-=a[i][j];
    }
    cout << f[m][n][m];
}