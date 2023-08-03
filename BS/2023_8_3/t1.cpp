#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100,M=5000,mod=1e9+7;
int n,K,mk;
ll a[N],p2[N];
ll f[N][M],ans;
int c[N];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    p2[0]=1;
    for(int i=1;i<=62;i++)p2[i]=p2[i]*2;
    cin >> n >> K;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        for(int j=62;j>=0;j--){
            if(p2[j]<a[i]){
                c[i]=j;
                mk+=j;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++){
        f[i][0]=1;
        for(int j=1;j<=mk;j++){
            for(int k=max(j-c[i],0);k<=j;k++){
                f[i][j]=(f[i][j]+f[i-1][k])%mod;
            }
            if(i==n)ans+=f[i][j];
        }
    }
    ans++;
    cout << ans;
    
}
