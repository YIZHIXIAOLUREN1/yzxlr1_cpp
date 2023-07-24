#include<bits/stdc++.h>
using namespace std;
#define N 105
int n,m;
const int mod=9999973;
int f[2][N][N];

int main(){
    cin >> n >> m;
    for(int j=0;j<=m;j++)
    for(int k=0;k<=m-j;k++){
        f[1][j][k]=1;
    }

    for(int i=2;i<=n;i++){
        int ni=(i&1),li=(i+1)&1;
        for(int j=0;j<=m;j++){
            for(int k=0;k<=m-j;k++){
                int l=m-j-k;
                f[ni][j][k]=f[li][j][k];
                if(j+1<=m&&k-1>=0)
                    f[ni][j][k]=(f[ni][j][k]+f[li][j+1][k-1]*(j+1))%mod;
                if(j-1>=0&&l<=m)
                    f[ni][j][k]=(f[ni][j][k]+f[li][j-1][k]*(l+1))%mod;
                if(k>=1&&l+1<=m)
                    f[ni][j][k]=(f[ni][j][k]+
                (f[li][j][k-1]*(j+1)%mod)*(l+1)%mod)%mod;
            }
        }
    }
    int ans=0;
    for(int j=0;j<=m;j++){
        for(int k=0;k<=m-j;k++){
            ans+=f[n&1][j][k];
        }
    }
    cout << ans;
}