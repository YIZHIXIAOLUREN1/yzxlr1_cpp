#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7,mod=1e9+7;
ll n,nn;
bool vis[N];
int p[N],tot=0;
int cnt[N];
ll ans;
void getprime(){
    for(int i=2;i<N;i++){
        if(!vis[i])p[++tot]=i;
        for(int j=1;j<=tot&&(ll)p[j]*i<N;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
ll qp(ll x,ll q){
    ll res=1;
    while(q){
        if(q&1)res=(ll)res*x%mod;
        x=(ll)x*x%mod;
        q>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getprime();
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        nn=n%mod;
        ans=1;
        for(int i=1;i<=tot&&p[i]*p[i]<=n;i++){
            cnt[i]=0;
            while(n%p[i]==0){
                cnt[i]++;
                n/=p[i];
            }
            cnt[i]/=2;
            ans=ans*qp(p[i],cnt[i])%mod;
        }
        ll sqn=sqrt(n);
        if(1ll*sqn*sqn==n){
            ans=ans*sqn%mod;
        }
        cout<<(nn*nn%mod+ans)%mod<<"\n";
    }
}
