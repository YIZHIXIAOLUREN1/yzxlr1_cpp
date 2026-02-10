#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+7;
ll n,m,k,ans;
bool check(ll x){
    ll t=n/x,r=n%x;
    return r*t+t*(t-1)/2*x<=k;
}
void Solve(){
    ans=0;
    cin>>n>>m>>k;
    if(n==1){cout<<"0\n";return;}
    if(m==1){cout<<"-1\n";return;}
    while(n>1){
    	if(k<n/2){
    		ll t=max((n-2*k)/k,1ll*1);
    		ans+=t;
    		n-=t*k;
    		continue;
    	}
        ll x=(__int128)n*(__int128)n/((__int128)(n+2*k));
        x=max(x,(n-1)/m+1);
        while(x<n&&!check(x))x++;
        while(x>(n-1)/m+1&&check(x-1))x--;
        ans++;
        n=x;
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
/*
n->x
n=x*t+r
r*t+t*(t-1)/2*x<=k

*/