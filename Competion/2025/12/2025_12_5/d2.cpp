#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll n,K,ans;
ll mmi,f[65][65];
void Solve(){
    cin>>n>>K;
    n<<=1;
    ans=0;
    for(int i=1;(1ll<<(i-1))<=n;i++){
        for(int j=0;j<=min(1ll*i,K);j++){
            f[i][j]=0;
        }
	}
    for(int i=1;(1ll<<(i-1))<=n;i++)mmi=i;
    for(int i=1;(1ll<<(i-1))<=n;i++){
        for(int j=0;j<=min(1ll*i,K);j++){
            int nlen=0,nst=0;
            for(int l=i;(1ll<<(l-1))<=n;l++){
                if((1ll<<l)&n||(l==i&&f[i][j])){
                    if((l==i&&f[i][j])||((1ll<<(l-1))&n)==0&&(!(l-1==i&&f[i][j]))){
                    	nst=l,nlen=1;
                    }
                    else nlen++;
                }else if(l&&(((1ll<<(l-1))&n)||(l-1==i&&f[i][j]))){
                    f[l][j+1]=max(f[l][j+1],f[i][j]+nlen);
                }
            }
        }
    }
    ll res=0,mk=0;
    for(int i=1;(1ll<<(i-1))<=n;i++){
        for(int j=0;j<=min(1ll*i,K);j++){
            res=max(res,f[i][j]+K-j);
        }
	}
	
    cout<<res<<"\n";
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
dp[i][j] 


*/
