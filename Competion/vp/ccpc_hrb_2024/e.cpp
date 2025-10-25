#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const ll N=507,mod=1e9+7;
int n,m;
int x[N];
int v[N];
int qp(int x,int q){
    int res=1;
    while(q){
        if(q&1)res=res*x%mod;
        x=x*x%mod;
        q>>=1;
    }
    return res;
}
int inv(int x){return qp(x,mod-2);}
int res,ans;
int cnm,cm,cn;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>x[i];
    sort(x+1,x+n+1);
    for(int i=1;i<=m;i++)cin>>v[i];
    cn=cm=cnm=1;
    for(int i=1;i<=n-1;i++)cn=cn*i%mod;
    for(int i=1;i<=m-1;i++)cm=cm*i%mod;
    for(int i=1;i<=n-m;i++)cnm=cnm*i%mod;
    cn=cn*inv(cm)%mod*inv(cnm)%mod;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int tp=qp(j,(m-1)/2)*qp(n-j+1,(m-1)/2)%mod;
            ans=(ans+(-x[j]*inv(v[i])%mod+mod)%mod*tp%mod)%mod;
            res=(res+tp)%mod;
        }
    }
    cout<<ans<<" "<<res<<"\n";
    cout<<ans*inv(res)%mod;
}
