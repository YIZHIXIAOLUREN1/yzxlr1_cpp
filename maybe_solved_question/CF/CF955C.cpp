#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


vector<ll> q;

ll po(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}

void init(){
	for(ll i=3;i<=59;i++){
		for(ll j=1;j<=pow(1e18,1.0/i);j++){
			ll x=po(j,i);
			ll sq=sqrt(x);
			if(sq*sq==x) continue;
			q.push_back(x);
		}
	}
	sort(q.begin(),q.end());
	q.erase(unique(q.begin(),q.end()),q.end());
}

ll qzh(ll x){
	ll res=sqrt(x);
	ll n=lower_bound(q.begin(),q.end(),x)-q.begin();
	if(n==q.size())n--;
	else if(q[n]>x)n--;
	return res+n;
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",qzh(r)-qzh(l-1));
	}
	return 0;
}