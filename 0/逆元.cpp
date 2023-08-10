#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod;
int qp(int x,int q){
    int res=1;
    while(q){
        if(q&1)res=(ll)res*x%mod;
        x=(ll)x*x%mod;
        q>>=1;
    }
    return res;
}
int inv1(int x){return qp(x,mod-2);}//费马小定理

void exgcd(ll a,ll b,ll &x,ll &y){
	if(a%b==0) x=0,y=1;
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
int inv(ll a,ll p){
	ll x,y;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}