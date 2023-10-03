#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=400,M=1e5+7,NN=316,mod=1e9+7;
int n,m;
int f[N][M];
int ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("thursday.in","r",stdin);
    freopen("thursday.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        memset(f,0,sizeof f);
        f[0][0]=1;
        ans=0;
        for(int i=1;i*(i+1)/2<=n+m;i++){
            int ma=i*(i+1)/2;
            for(int j=max(ma-m,0);j<=n;j++){
                f[i][j]=f[i-1][j];
                if(j-i>=0)f[i][j]=(f[i][j]+f[i-1][j-i])%mod;
                ans=(ans+f[i][j])%mod;
            }
        }
        cout << ans << "\n";
    }
}
/*
0  0  1  2  3  4  5  6  7  8  9 10
1  1  1                            2
2  1  1  1  1                      4      
3  1  1  1  2  1                   6               
4              2                   2                  
*/