#include<bits/stdc++.h>
using namespace std;
#define N 105
#define ll long long
int n,m;
const int mod=9999973;
int f[2][N][N];
ll C(int x){
	return (((ll)x*((ll)x-1))/2)%mod;
}

int main(){
    cin >> n >> m;
    f[0][0][0]=1;

    for(int i=1;i<=n;i++){
        int ni=(i&1),li=(i+1)&1;
        for(int j=0;j<=m;j++){
            for(int k=0;k<=m-j;k++){
                int l=m-j-k;
                f[ni][j][k]=f[li][j][k];
                if(k>=1)
                    f[ni][j][k]=(f[ni][j][k]+f[li][j+1][k-1]*(j+1))%mod;
                if(j>=1)
                    f[ni][j][k]=(f[ni][j][k]+f[li][j-1][k]*(l+1))%mod;
                if(k>=1)
                    f[ni][j][k]=(f[ni][j][k]+
                (f[li][j][k-1]*j%mod)*(l+1)%mod)%mod;
                if(j>=2)f[ni][j][k]=(f[ni][j][k]+
                f[li][j-2][k]*C(l+2)%mod)%mod;
                if(k>=2)f[ni][j][k]=(f[ni][j][k]+
                f[li][j+2][k-2]*C(j+2)%mod)%mod;
            }
        }
    }
    int ans=0;
    for(int j=0;j<=m;j++){
        for(int k=0;k<=m;k++){
            ans=(ans+f[n&1][j][k])%mod;
        }
    }
    cout << ans%mod;
}