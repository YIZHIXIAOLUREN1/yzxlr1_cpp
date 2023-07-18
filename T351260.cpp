#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define N 1000100
#define ll long long
ll n;
ll t1,t2,tn,s,ans;
ll Al(ll x){
    return (x>1)?Al(x-1)*x%mod:1;
}

int main(){
    scanf("%lld",&n);
    t1=Al(n-1);
    t2=1;
    for(int i=1;i<=n;i++){
    	ll x1;
        if(i>1)t2=t2*10%mod;
        tn=(tn+t2*t1%mod)%mod;
        scanf("%lld",&x1);
        s+=x1;
    }
    ans=s*tn%mod;
    printf("%lld",ans);
}