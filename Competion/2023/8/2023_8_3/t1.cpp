#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100,M=5000,mod=1e9+7;
int n,K,mk;
ll a[N],p2[N];
int f[N][M],g[N][M],ans;
bool ttr;
int c[N];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    p2[0]=1;
    for(int i=1;i<=62;i++)p2[i]=p2[i-1]*2;
    cin >> n >> K;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        for(int j=62;j>=0;j--){
            if(p2[j]<=a[i]){
                c[i]=j+1;
                mk+=j+1;
                break;
            }
        }
        //printf("%d:%d\n",i,c[i]);//
    }
	if(K>mk)ttr=1;
	mk=min(mk,K);
	f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=mk;j++){
            for(int k=max(j-c[i],0);k<=j;k++){
                f[i][j]=(f[i][j]+f[i-1][k])%mod;
                if(k==j-c[i])g[i][j]=(g[i][j]+f[i-1][k])%mod;
                else if(g[i-1][k])g[i][j]=(g[i][j]+g[i-1][k])%mod;
            }
            //printf("%d %d:%lld:%lld\n",i,j,f[i][j],g[i][j]);//
        }
    }
    if(ttr)for(int j=0;j<=mk;j++)ans=(ans+g[n][j])%mod;
    else{
    	for(int j=0;j<mk;j++)ans=(ans+g[n][j])%mod;
    	ans=(ans+f[n][mk])%mod;
    }
    //cout << ttr<<"\n";//
    cout << ans;
}