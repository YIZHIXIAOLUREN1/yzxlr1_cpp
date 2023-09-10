#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll n,k;

ll qp(ll x,ll q){
    ll res=1;
    while(q){
        if(q&1ll*1)res=res*x%mod;
        x=x*x%mod;
        q>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    cout << (qp(k,n)+n-2+mod)%mod;
}

/*
a=k^n
ans=a*n-(a-1)*(n-1)-1
=a*n-a*n+a+n-1-1
=a+n-2
=k^n+n-2
*/